# frozen_string_literal: true

module GTK


    class Runtime

      # FILLTHIS
      alias_method :__original_quit__!, :quit! unless GTK::Runtime.instance_methods.include?(:__original_quit__!)
  
      def quit!
        #quit stuff here
        $app.db.close
        __original_quit__!
      end
    end
end


#++++++++++++++++++++++++++++++++++
# IO COMPONENTS
#++++++++++++++++++++++++++++++++++

require 'app/io/db.rb'


#++++++++++++++++++++++++++++++++++
# TICK
#++++++++++++++++++++++++++++++++++
require 'app/tick.rb'

