$gtk.ffi_misc.gtk_dlopen('sqlite3')
putz 'imported sqlite3'
$gtk.ffi_misc.gtk_dlopen('ext_libsqlite3')
putz 'imported ext_libsqlite3'
include FFI::LIBSQLITE3
putz 'included FFI::LIBSQLITE3'


class DB

    # Gives sqlite version
    #
    # @return [String]
    def self.lib_version
        return sqlite3_libversion().str
    end


    def initialize
        @dbptr = Sqlite3PointerPointer.new
        @stmt = Sqlite3_stmtPointerPointer.new
        @stmt_leftovers = CharPointerPointer.new
        @schema_v = 4 
        sqlite3_open("data.db", @dbptr)
        prep_exec(query_drop_tables)
        prep_exec(query_init_tables)
        prep_exec(query_update_config)
    end


    def close
        sqlite3_close(@dbptr.value)
    end


    def draw_table(parent, table)
        q = query_select_all(table)
        prepare_statement(q)
        exec_statement
        itemize_table("ui_table", parent)
    end


    def exec_statement
        res = sqlite3_step(@stmt.value)
        return res
    end


    def get_column
        putz sqlite3_column_count(@stmt.value)
        res = sqlite3_column_text(@stmt.value,0)
        return res
    end


    def interpret_code(res_err_int)
        if res_err_int == 0
            return "SQLITE_OK"
        else
            return sqlite3_errstr(res_err_int).str
        end
    end


    def print_table(table)
        q = query_select_all(table)
        prepare_statement(q)
        exec_statement
        itemize_table
    end


    def prep_exec(q)
        prepare_statement(q)
        exec_statement
    end

    def prepare_statement(q)
        res = sqlite3_prepare_v2(@dbptr.value, q, -1, @stmt, @stmt_leftovers)
        return res
    end

    def time_string
        q = query_select_datetime
        prepare_statement(q)
        exec_statement
        items = itemize_table("collection")
        items[0]
    end

    def itemize_table(fmt="text_table", parent=self)
        num = sqlite3_column_count(@stmt.value)
        col_types = []
        0.upto(num-1){ |i|
            col_types[i] = sqlite3_column_type(@stmt.value, i)
        }
        items = []
        step_res = 0
        while (step_res == 0 || step_res == 100) #101 = SQLITE SPEAK FOR DONE
            0.upto(num-1){ |i|
                if col_types[i] == 1
                    items << sqlite3_column_int(@stmt.value, i).to_s
                end
                if col_types[i] == 3
                    items << sqlite3_column_text(@stmt.value, i).str
                end
            }
            step_res = exec_statement
        end
        if fmt == "text_table"
            pretty_print_strings_as_table(items, num)
        elsif fmt == "ui_table"
            pretty_draw_strings_as_table(parent, items, num)
        else
            return items
        end

    end

    def query_select_all(table)
        q = "SELECT * FROM #{table};"
        return q
    end

    def query_drop_tables
        q = "DROP TABLE IF EXISTS config;"
        return q
    end

    def query_init_tables
        q = 'CREATE TABLE config(' \
        'id INTEGER PRIMARY KEY AUTOINCREMENT,'\
        'property TEXT NOT NULL,' \
        'data INTEGER NOT NULL,' \
        'last_modified TIMESTAMP DEFAULT CURRENT_TIMESTAMP);'
        return q
    end

    def query_select_datetime
        q = "SELECT datetime('now','localtime');"
    end

    def query_update_config
        q = "INSERT INTO config (property, data) VALUES ('schema_v', #{@schema_v}); "
        return q
    end

    def query_table_names
        q = "SELECT name FROM sqlite_schema WHERE type='table' ORDER BY name;"
        return q
    end

end
