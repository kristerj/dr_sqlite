#include <mruby.h>
#include <string.h>
#include <assert.h>
#include <mruby/string.h>
#include <mruby/data.h>
#include <dragonruby.h>
#include "app/lib/sqlite3.h"

static drb_api_t *drb_api;

static void drb_free_foreign_object_indirect(mrb_state *state, void *pointer) {
    drb_api->drb_free_foreign_object(state, pointer);
}
static int drb_ffi__ZTSi_FromRuby(mrb_state *state, mrb_value self) {
    drb_api->drb_typecheck_int(state, self);
    return mrb_fixnum(self);
}
static mrb_value drb_ffi__ZTSi_ToRuby(mrb_state *state, int value) {
    return mrb_fixnum_value(value);
}
struct drb_foreign_object_ZTSPc {
    drb_foreign_object_kind kind;
    char *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPc = {"char*", drb_free_foreign_object_indirect};
static char *drb_ffi__ZTSPc_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    if (mrb_type(self) == MRB_TT_STRING)
        return RSTRING_PTR(self);
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "CharPointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPc);
    return ((struct drb_foreign_object_ZTSPc *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPc_ToRuby(mrb_state *state, char *value) {
    struct drb_foreign_object_ZTSPc *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPc));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "CharPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPc);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSP7sqlite3 {
    drb_foreign_object_kind kind;
    sqlite3 *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSP7sqlite3 = {"sqlite3*", drb_free_foreign_object_indirect};
static sqlite3 *drb_ffi__ZTSP7sqlite3_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSP7sqlite3);
    return ((struct drb_foreign_object_ZTSP7sqlite3 *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSP7sqlite3_ToRuby(mrb_state *state, sqlite3 *value) {
    struct drb_foreign_object_ZTSP7sqlite3 *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP7sqlite3));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSP7sqlite3);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFiPviPPcS1_E {
    drb_foreign_object_kind kind;
    int (*value)(void *, int, char **, char **);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFiPviPPcS1_E = {"Function_0*", drb_free_foreign_object_indirect};
static int (*drb_ffi__ZTSPFiPviPPcS1_E_FromRuby(mrb_state *state, mrb_value self))(void *, int, char **, char **) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_0Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFiPviPPcS1_E);
    return ((struct drb_foreign_object_ZTSPFiPviPPcS1_E *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFiPviPPcS1_E_ToRuby(mrb_state *state, int (*value)(void *, int, char **, char **)) {
    struct drb_foreign_object_ZTSPFiPviPPcS1_E *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiPviPPcS1_E));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_0Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFiPviPPcS1_E);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPv {
    drb_foreign_object_kind kind;
    void *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPv = {"void*", drb_free_foreign_object_indirect};
static void *drb_ffi__ZTSPv_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "VoidPointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPv);
    return ((struct drb_foreign_object_ZTSPv *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPv_ToRuby(mrb_state *state, void *value) {
    struct drb_foreign_object_ZTSPv *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPv));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "VoidPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPv);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPPc {
    drb_foreign_object_kind kind;
    char **value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPPc = {"char**", drb_free_foreign_object_indirect};
static char **drb_ffi__ZTSPPc_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "CharPointerPointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPPc);
    return ((struct drb_foreign_object_ZTSPPc *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPPc_ToRuby(mrb_state *state, char **value) {
    struct drb_foreign_object_ZTSPPc *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPPc));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "CharPointerPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPPc);
    return mrb_obj_value(rdata);
}
static sqlite3_int64 drb_ffi__ZTSx_FromRuby(mrb_state *state, mrb_value self) {
    drb_api->drb_typecheck_int(state, self);
    return mrb_fixnum(self);
}
static mrb_value drb_ffi__ZTSx_ToRuby(mrb_state *state, sqlite3_int64 value) {
    return mrb_fixnum_value(value);
}
struct drb_foreign_object_ZTSPFiPviE {
    drb_foreign_object_kind kind;
    int (*value)(void *, int);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFiPviE = {"Function_1*", drb_free_foreign_object_indirect};
static int (*drb_ffi__ZTSPFiPviE_FromRuby(mrb_state *state, mrb_value self))(void *, int) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_1Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFiPviE);
    return ((struct drb_foreign_object_ZTSPFiPviE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFiPviE_ToRuby(mrb_state *state, int (*value)(void *, int)) {
    struct drb_foreign_object_ZTSPFiPviE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiPviE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_1Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFiPviE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPPPc {
    drb_foreign_object_kind kind;
    char ***value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPPPc = {"char***", drb_free_foreign_object_indirect};
static char ***drb_ffi__ZTSPPPc_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "CharPointerPointerPointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPPPc);
    return ((struct drb_foreign_object_ZTSPPPc *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPPPc_ToRuby(mrb_state *state, char ***value) {
    struct drb_foreign_object_ZTSPPPc *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPPPc));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "CharPointerPointerPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPPPc);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPi {
    drb_foreign_object_kind kind;
    int *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPi = {"int*", drb_free_foreign_object_indirect};
static int *drb_ffi__ZTSPi_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "IntPointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPi);
    return ((struct drb_foreign_object_ZTSPi *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPi_ToRuby(mrb_state *state, int *value) {
    struct drb_foreign_object_ZTSPi *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPi));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "IntPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPi);
    return mrb_obj_value(rdata);
}
static sqlite3_uint64 drb_ffi__ZTSy_FromRuby(mrb_state *state, mrb_value self) {
    drb_api->drb_typecheck_int(state, self);
    return mrb_fixnum(self);
}
static mrb_value drb_ffi__ZTSy_ToRuby(mrb_state *state, sqlite3_uint64 value) {
    return mrb_fixnum_value(value);
}
struct drb_foreign_object_ZTSPFiPviPKcS1_S1_S1_E {
    drb_foreign_object_kind kind;
    int (*value)(void *, int, const char *, const char *, const char *, const char *);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFiPviPKcS1_S1_S1_E = {"Function_2*", drb_free_foreign_object_indirect};
static int (*drb_ffi__ZTSPFiPviPKcS1_S1_S1_E_FromRuby(mrb_state *state, mrb_value self))(void *, int, const char *, const char *, const char *, const char *) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_2Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFiPviPKcS1_S1_S1_E);
    return ((struct drb_foreign_object_ZTSPFiPviPKcS1_S1_S1_E *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFiPviPKcS1_S1_S1_E_ToRuby(mrb_state *state, int (*value)(void *, int, const char *, const char *, const char *, const char *)) {
    struct drb_foreign_object_ZTSPFiPviPKcS1_S1_S1_E *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiPviPKcS1_S1_S1_E));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_2Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFiPviPKcS1_S1_S1_E);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFvPvPKcE {
    drb_foreign_object_kind kind;
    void (*value)(void *, const char *);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFvPvPKcE = {"Function_3*", drb_free_foreign_object_indirect};
static void (*drb_ffi__ZTSPFvPvPKcE_FromRuby(mrb_state *state, mrb_value self))(void *, const char *) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_3Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFvPvPKcE);
    return ((struct drb_foreign_object_ZTSPFvPvPKcE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFvPvPKcE_ToRuby(mrb_state *state, void (*value)(void *, const char *)) {
    struct drb_foreign_object_ZTSPFvPvPKcE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFvPvPKcE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_3Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFvPvPKcE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFvPvPKcyE {
    drb_foreign_object_kind kind;
    void (*value)(void *, const char *, sqlite3_uint64);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFvPvPKcyE = {"Function_4*", drb_free_foreign_object_indirect};
static void (*drb_ffi__ZTSPFvPvPKcyE_FromRuby(mrb_state *state, mrb_value self))(void *, const char *, sqlite3_uint64) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_4Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFvPvPKcyE);
    return ((struct drb_foreign_object_ZTSPFvPvPKcyE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFvPvPKcyE_ToRuby(mrb_state *state, void (*value)(void *, const char *, sqlite3_uint64)) {
    struct drb_foreign_object_ZTSPFvPvPKcyE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFvPvPKcyE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_4Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFvPvPKcyE);
    return mrb_obj_value(rdata);
}
static unsigned int drb_ffi__ZTSj_FromRuby(mrb_state *state, mrb_value self) {
    drb_api->drb_typecheck_int(state, self);
    return mrb_fixnum(self);
}
static mrb_value drb_ffi__ZTSj_ToRuby(mrb_state *state, unsigned int value) {
    return mrb_fixnum_value(value);
}
struct drb_foreign_object_ZTSPFijPvS_S_E {
    drb_foreign_object_kind kind;
    int (*value)(unsigned int, void *, void *, void *);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFijPvS_S_E = {"Function_5*", drb_free_foreign_object_indirect};
static int (*drb_ffi__ZTSPFijPvS_S_E_FromRuby(mrb_state *state, mrb_value self))(unsigned int, void *, void *, void *) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_5Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFijPvS_S_E);
    return ((struct drb_foreign_object_ZTSPFijPvS_S_E *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFijPvS_S_E_ToRuby(mrb_state *state, int (*value)(unsigned int, void *, void *, void *)) {
    struct drb_foreign_object_ZTSPFijPvS_S_E *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFijPvS_S_E));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_5Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFijPvS_S_E);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFiPvE {
    drb_foreign_object_kind kind;
    int (*value)(void *);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFiPvE = {"Function_6*", drb_free_foreign_object_indirect};
static int (*drb_ffi__ZTSPFiPvE_FromRuby(mrb_state *state, mrb_value self))(void *) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_6Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFiPvE);
    return ((struct drb_foreign_object_ZTSPFiPvE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFiPvE_ToRuby(mrb_state *state, int (*value)(void *)) {
    struct drb_foreign_object_ZTSPFiPvE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiPvE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_6Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFiPvE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPP7sqlite3 {
    drb_foreign_object_kind kind;
    sqlite3 **value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPP7sqlite3 = {"sqlite3**", drb_free_foreign_object_indirect};
static sqlite3 **drb_ffi__ZTSPP7sqlite3_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3PointerPointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPP7sqlite3);
    return ((struct drb_foreign_object_ZTSPP7sqlite3 *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPP7sqlite3_ToRuby(mrb_state *state, sqlite3 **value) {
    struct drb_foreign_object_ZTSPP7sqlite3 *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPP7sqlite3));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3PointerPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPP7sqlite3);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSP12sqlite3_file {
    drb_foreign_object_kind kind;
    sqlite3_file *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSP12sqlite3_file = {"sqlite3_file*", drb_free_foreign_object_indirect};
static sqlite3_file *drb_ffi__ZTSP12sqlite3_file_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3_filePointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSP12sqlite3_file);
    return ((struct drb_foreign_object_ZTSP12sqlite3_file *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSP12sqlite3_file_ToRuby(mrb_state *state, sqlite3_file *value) {
    struct drb_foreign_object_ZTSP12sqlite3_file *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP12sqlite3_file));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3_filePointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSP12sqlite3_file);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPP12sqlite3_stmt {
    drb_foreign_object_kind kind;
    sqlite3_stmt **value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPP12sqlite3_stmt = {"sqlite3_stmt**", drb_free_foreign_object_indirect};
static sqlite3_stmt **drb_ffi__ZTSPP12sqlite3_stmt_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3_stmtPointerPointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPP12sqlite3_stmt);
    return ((struct drb_foreign_object_ZTSPP12sqlite3_stmt *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPP12sqlite3_stmt_ToRuby(mrb_state *state, sqlite3_stmt **value) {
    struct drb_foreign_object_ZTSPP12sqlite3_stmt *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPP12sqlite3_stmt));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3_stmtPointerPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPP12sqlite3_stmt);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPPv {
    drb_foreign_object_kind kind;
    void **value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPPv = {"void**", drb_free_foreign_object_indirect};
static void **drb_ffi__ZTSPPv_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "VoidPointerPointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPPv);
    return ((struct drb_foreign_object_ZTSPPv *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPPv_ToRuby(mrb_state *state, void **value) {
    struct drb_foreign_object_ZTSPPv *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPPv));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "VoidPointerPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPPv);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSP12sqlite3_stmt {
    drb_foreign_object_kind kind;
    sqlite3_stmt *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSP12sqlite3_stmt = {"sqlite3_stmt*", drb_free_foreign_object_indirect};
static sqlite3_stmt *drb_ffi__ZTSP12sqlite3_stmt_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3_stmtPointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSP12sqlite3_stmt);
    return ((struct drb_foreign_object_ZTSP12sqlite3_stmt *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSP12sqlite3_stmt_ToRuby(mrb_state *state, sqlite3_stmt *value) {
    struct drb_foreign_object_ZTSP12sqlite3_stmt *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP12sqlite3_stmt));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3_stmtPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSP12sqlite3_stmt);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFvPvE {
    drb_foreign_object_kind kind;
    void (*value)(void *);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFvPvE = {"Function_7*", drb_free_foreign_object_indirect};
static void (*drb_ffi__ZTSPFvPvE_FromRuby(mrb_state *state, mrb_value self))(void *) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_7Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFvPvE);
    return ((struct drb_foreign_object_ZTSPFvPvE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFvPvE_ToRuby(mrb_state *state, void (*value)(void *)) {
    struct drb_foreign_object_ZTSPFvPvE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFvPvE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_7Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFvPvE);
    return mrb_obj_value(rdata);
}
static double drb_ffi__ZTSd_FromRuby(mrb_state *state, mrb_value self) {
    drb_api->drb_typecheck_float(state, self);
    return mrb_float(self);
}
static mrb_value drb_ffi__ZTSd_ToRuby(mrb_state *state, double value) {
    return drb_api->drb_float_value(state, value);
}
static unsigned char drb_ffi__ZTSh_FromRuby(mrb_state *state, mrb_value self) {
    drb_api->drb_typecheck_int(state, self);
    return mrb_fixnum(self);
}
static mrb_value drb_ffi__ZTSh_ToRuby(mrb_state *state, unsigned char value) {
    return mrb_fixnum_value(value);
}
struct drb_foreign_object_ZTSP13sqlite3_value {
    drb_foreign_object_kind kind;
    sqlite3_value *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSP13sqlite3_value = {"sqlite3_value*", drb_free_foreign_object_indirect};
static sqlite3_value *drb_ffi__ZTSP13sqlite3_value_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3_valuePointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSP13sqlite3_value);
    return ((struct drb_foreign_object_ZTSP13sqlite3_value *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSP13sqlite3_value_ToRuby(mrb_state *state, sqlite3_value *value) {
    struct drb_foreign_object_ZTSP13sqlite3_value *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP13sqlite3_value));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3_valuePointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSP13sqlite3_value);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPh {
    drb_foreign_object_kind kind;
    unsigned char *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPh = {"unsigned char*", drb_free_foreign_object_indirect};
static unsigned char *drb_ffi__ZTSPh_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    if (mrb_type(self) == MRB_TT_STRING)
        return RSTRING_PTR(self);
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Unsigned_charPointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPh);
    return ((struct drb_foreign_object_ZTSPh *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPh_ToRuby(mrb_state *state, unsigned char *value) {
    struct drb_foreign_object_ZTSPh *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPh));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Unsigned_charPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPh);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFvP15sqlite3_contextiPP13sqlite3_valueE {
    drb_foreign_object_kind kind;
    void (*value)(sqlite3_context *, int, sqlite3_value **);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFvP15sqlite3_contextiPP13sqlite3_valueE = {"Function_8*", drb_free_foreign_object_indirect};
static void (*drb_ffi__ZTSPFvP15sqlite3_contextiPP13sqlite3_valueE_FromRuby(mrb_state *state, mrb_value self))(sqlite3_context *, int, sqlite3_value **) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_8Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFvP15sqlite3_contextiPP13sqlite3_valueE);
    return ((struct drb_foreign_object_ZTSPFvP15sqlite3_contextiPP13sqlite3_valueE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFvP15sqlite3_contextiPP13sqlite3_valueE_ToRuby(mrb_state *state, void (*value)(sqlite3_context *, int, sqlite3_value **)) {
    struct drb_foreign_object_ZTSPFvP15sqlite3_contextiPP13sqlite3_valueE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFvP15sqlite3_contextiPP13sqlite3_valueE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_8Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFvP15sqlite3_contextiPP13sqlite3_valueE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFvP15sqlite3_contextE {
    drb_foreign_object_kind kind;
    void (*value)(sqlite3_context *);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFvP15sqlite3_contextE = {"Function_9*", drb_free_foreign_object_indirect};
static void (*drb_ffi__ZTSPFvP15sqlite3_contextE_FromRuby(mrb_state *state, mrb_value self))(sqlite3_context *) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_9Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFvP15sqlite3_contextE);
    return ((struct drb_foreign_object_ZTSPFvP15sqlite3_contextE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFvP15sqlite3_contextE_ToRuby(mrb_state *state, void (*value)(sqlite3_context *)) {
    struct drb_foreign_object_ZTSPFvP15sqlite3_contextE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFvP15sqlite3_contextE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_9Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFvP15sqlite3_contextE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSP15sqlite3_context {
    drb_foreign_object_kind kind;
    sqlite3_context *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSP15sqlite3_context = {"sqlite3_context*", drb_free_foreign_object_indirect};
static sqlite3_context *drb_ffi__ZTSP15sqlite3_context_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3_contextPointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSP15sqlite3_context);
    return ((struct drb_foreign_object_ZTSP15sqlite3_context *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSP15sqlite3_context_ToRuby(mrb_state *state, sqlite3_context *value) {
    struct drb_foreign_object_ZTSP15sqlite3_context *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP15sqlite3_context));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3_contextPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSP15sqlite3_context);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFvPvxiE {
    drb_foreign_object_kind kind;
    void (*value)(void *, sqlite3_int64, int);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFvPvxiE = {"Function_10*", drb_free_foreign_object_indirect};
static void (*drb_ffi__ZTSPFvPvxiE_FromRuby(mrb_state *state, mrb_value self))(void *, sqlite3_int64, int) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_10Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFvPvxiE);
    return ((struct drb_foreign_object_ZTSPFvPvxiE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFvPvxiE_ToRuby(mrb_state *state, void (*value)(void *, sqlite3_int64, int)) {
    struct drb_foreign_object_ZTSPFvPvxiE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFvPvxiE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_10Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFvPvxiE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFiPviPKviS1_E {
    drb_foreign_object_kind kind;
    int (*value)(void *, int, const void *, int, const void *);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFiPviPKviS1_E = {"Function_11*", drb_free_foreign_object_indirect};
static int (*drb_ffi__ZTSPFiPviPKviS1_E_FromRuby(mrb_state *state, mrb_value self))(void *, int, const void *, int, const void *) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_11Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFiPviPKviS1_E);
    return ((struct drb_foreign_object_ZTSPFiPviPKviS1_E *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFiPviPKviS1_E_ToRuby(mrb_state *state, int (*value)(void *, int, const void *, int, const void *)) {
    struct drb_foreign_object_ZTSPFiPviPKviS1_E *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiPviPKviS1_E));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_11Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFiPviPKviS1_E);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFvPvP7sqlite3iPKcE {
    drb_foreign_object_kind kind;
    void (*value)(void *, sqlite3 *, int, const char *);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFvPvP7sqlite3iPKcE = {"Function_12*", drb_free_foreign_object_indirect};
static void (*drb_ffi__ZTSPFvPvP7sqlite3iPKcE_FromRuby(mrb_state *state, mrb_value self))(void *, sqlite3 *, int, const char *) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_12Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFvPvP7sqlite3iPKcE);
    return ((struct drb_foreign_object_ZTSPFvPvP7sqlite3iPKcE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFvPvP7sqlite3iPKcE_ToRuby(mrb_state *state, void (*value)(void *, sqlite3 *, int, const char *)) {
    struct drb_foreign_object_ZTSPFvPvP7sqlite3iPKcE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFvPvP7sqlite3iPKcE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_12Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFvPvP7sqlite3iPKcE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFvPvP7sqlite3iPKvE {
    drb_foreign_object_kind kind;
    void (*value)(void *, sqlite3 *, int, const void *);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFvPvP7sqlite3iPKvE = {"Function_13*", drb_free_foreign_object_indirect};
static void (*drb_ffi__ZTSPFvPvP7sqlite3iPKvE_FromRuby(mrb_state *state, mrb_value self))(void *, sqlite3 *, int, const void *) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_13Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFvPvP7sqlite3iPKvE);
    return ((struct drb_foreign_object_ZTSPFvPvP7sqlite3iPKvE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFvPvP7sqlite3iPKvE_ToRuby(mrb_state *state, void (*value)(void *, sqlite3 *, int, const void *)) {
    struct drb_foreign_object_ZTSPFvPvP7sqlite3iPKvE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFvPvP7sqlite3iPKvE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_13Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFvPvP7sqlite3iPKvE);
    return mrb_obj_value(rdata);
}
static unsigned long drb_ffi__ZTSm_FromRuby(mrb_state *state, mrb_value self) {
    drb_api->drb_typecheck_int(state, self);
    return mrb_fixnum(self);
}
static mrb_value drb_ffi__ZTSm_ToRuby(mrb_state *state, unsigned long value) {
    return mrb_fixnum_value(value);
}
struct drb_foreign_object_ZTSPFjPvPKcjjjE {
    drb_foreign_object_kind kind;
    unsigned int (*value)(void *, const char *, unsigned int, unsigned int, unsigned int);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFjPvPKcjjjE = {"Function_14*", drb_free_foreign_object_indirect};
static unsigned int (*drb_ffi__ZTSPFjPvPKcjjjE_FromRuby(mrb_state *state, mrb_value self))(void *, const char *, unsigned int, unsigned int, unsigned int) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_14Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFjPvPKcjjjE);
    return ((struct drb_foreign_object_ZTSPFjPvPKcjjjE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFjPvPKcjjjE_ToRuby(mrb_state *state, unsigned int (*value)(void *, const char *, unsigned int, unsigned int, unsigned int)) {
    struct drb_foreign_object_ZTSPFjPvPKcjjjE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFjPvPKcjjjE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_14Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFjPvPKcjjjE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFvPviPKcS1_xE {
    drb_foreign_object_kind kind;
    void (*value)(void *, int, const char *, const char *, sqlite3_int64);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFvPviPKcS1_xE = {"Function_15*", drb_free_foreign_object_indirect};
static void (*drb_ffi__ZTSPFvPviPKcS1_xE_FromRuby(mrb_state *state, mrb_value self))(void *, int, const char *, const char *, sqlite3_int64) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_15Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFvPviPKcS1_xE);
    return ((struct drb_foreign_object_ZTSPFvPviPKcS1_xE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFvPviPKcS1_xE_ToRuby(mrb_state *state, void (*value)(void *, int, const char *, const char *, sqlite3_int64)) {
    struct drb_foreign_object_ZTSPFvPviPKcS1_xE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFvPviPKcS1_xE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_15Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFvPviPKcS1_xE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFvvE {
    drb_foreign_object_kind kind;
    void (*value)(void);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFvvE = {"Function_16*", drb_free_foreign_object_indirect};
static void (*drb_ffi__ZTSPFvvE_FromRuby(mrb_state *state, mrb_value self))(void) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_16Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFvvE);
    return ((struct drb_foreign_object_ZTSPFvvE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFvvE_ToRuby(mrb_state *state, void (*value)(void)) {
    struct drb_foreign_object_ZTSPFvvE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFvvE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_16Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFvvE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSP14sqlite3_module {
    drb_foreign_object_kind kind;
    sqlite3_module *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSP14sqlite3_module = {"sqlite3_module*", drb_free_foreign_object_indirect};
static sqlite3_module *drb_ffi__ZTSP14sqlite3_module_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3_modulePointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSP14sqlite3_module);
    return ((struct drb_foreign_object_ZTSP14sqlite3_module *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSP14sqlite3_module_ToRuby(mrb_state *state, sqlite3_module *value) {
    struct drb_foreign_object_ZTSP14sqlite3_module *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP14sqlite3_module));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3_modulePointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSP14sqlite3_module);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPP12sqlite3_blob {
    drb_foreign_object_kind kind;
    sqlite3_blob **value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPP12sqlite3_blob = {"sqlite3_blob**", drb_free_foreign_object_indirect};
static sqlite3_blob **drb_ffi__ZTSPP12sqlite3_blob_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3_blobPointerPointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPP12sqlite3_blob);
    return ((struct drb_foreign_object_ZTSPP12sqlite3_blob *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPP12sqlite3_blob_ToRuby(mrb_state *state, sqlite3_blob **value) {
    struct drb_foreign_object_ZTSPP12sqlite3_blob *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPP12sqlite3_blob));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3_blobPointerPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPP12sqlite3_blob);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSP12sqlite3_blob {
    drb_foreign_object_kind kind;
    sqlite3_blob *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSP12sqlite3_blob = {"sqlite3_blob*", drb_free_foreign_object_indirect};
static sqlite3_blob *drb_ffi__ZTSP12sqlite3_blob_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3_blobPointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSP12sqlite3_blob);
    return ((struct drb_foreign_object_ZTSP12sqlite3_blob *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSP12sqlite3_blob_ToRuby(mrb_state *state, sqlite3_blob *value) {
    struct drb_foreign_object_ZTSP12sqlite3_blob *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP12sqlite3_blob));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3_blobPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSP12sqlite3_blob);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSP11sqlite3_vfs {
    drb_foreign_object_kind kind;
    sqlite3_vfs *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSP11sqlite3_vfs = {"sqlite3_vfs*", drb_free_foreign_object_indirect};
static sqlite3_vfs *drb_ffi__ZTSP11sqlite3_vfs_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3_vfsPointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSP11sqlite3_vfs);
    return ((struct drb_foreign_object_ZTSP11sqlite3_vfs *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSP11sqlite3_vfs_ToRuby(mrb_state *state, sqlite3_vfs *value) {
    struct drb_foreign_object_ZTSP11sqlite3_vfs *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP11sqlite3_vfs));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3_vfsPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSP11sqlite3_vfs);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSP13sqlite3_mutex {
    drb_foreign_object_kind kind;
    sqlite3_mutex *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSP13sqlite3_mutex = {"sqlite3_mutex*", drb_free_foreign_object_indirect};
static sqlite3_mutex *drb_ffi__ZTSP13sqlite3_mutex_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3_mutexPointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSP13sqlite3_mutex);
    return ((struct drb_foreign_object_ZTSP13sqlite3_mutex *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSP13sqlite3_mutex_ToRuby(mrb_state *state, sqlite3_mutex *value) {
    struct drb_foreign_object_ZTSP13sqlite3_mutex *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP13sqlite3_mutex));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3_mutexPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSP13sqlite3_mutex);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSP11sqlite3_str {
    drb_foreign_object_kind kind;
    sqlite3_str *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSP11sqlite3_str = {"sqlite3_str*", drb_free_foreign_object_indirect};
static sqlite3_str *drb_ffi__ZTSP11sqlite3_str_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3_strPointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSP11sqlite3_str);
    return ((struct drb_foreign_object_ZTSP11sqlite3_str *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSP11sqlite3_str_ToRuby(mrb_state *state, sqlite3_str *value) {
    struct drb_foreign_object_ZTSP11sqlite3_str *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP11sqlite3_str));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3_strPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSP11sqlite3_str);
    return mrb_obj_value(rdata);
}
static char drb_ffi__ZTSc_FromRuby(mrb_state *state, mrb_value self) {
    drb_api->drb_typecheck_int(state, self);
    return mrb_fixnum(self);
}
static mrb_value drb_ffi__ZTSc_ToRuby(mrb_state *state, char value) {
    return mrb_fixnum_value(value);
}
struct drb_foreign_object_ZTSPx {
    drb_foreign_object_kind kind;
    sqlite3_int64 *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPx = {"long long*", drb_free_foreign_object_indirect};
static sqlite3_int64 *drb_ffi__ZTSPx_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Long_longPointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPx);
    return ((struct drb_foreign_object_ZTSPx *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPx_ToRuby(mrb_state *state, sqlite3_int64 *value) {
    struct drb_foreign_object_ZTSPx *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPx));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Long_longPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPx);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSP14sqlite3_backup {
    drb_foreign_object_kind kind;
    sqlite3_backup *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSP14sqlite3_backup = {"sqlite3_backup*", drb_free_foreign_object_indirect};
static sqlite3_backup *drb_ffi__ZTSP14sqlite3_backup_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3_backupPointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSP14sqlite3_backup);
    return ((struct drb_foreign_object_ZTSP14sqlite3_backup *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSP14sqlite3_backup_ToRuby(mrb_state *state, sqlite3_backup *value) {
    struct drb_foreign_object_ZTSP14sqlite3_backup *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP14sqlite3_backup));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3_backupPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSP14sqlite3_backup);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFiPvP7sqlite3PKciE {
    drb_foreign_object_kind kind;
    int (*value)(void *, sqlite3 *, const char *, int);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFiPvP7sqlite3PKciE = {"Function_17*", drb_free_foreign_object_indirect};
static int (*drb_ffi__ZTSPFiPvP7sqlite3PKciE_FromRuby(mrb_state *state, mrb_value self))(void *, sqlite3 *, const char *, int) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_17Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFiPvP7sqlite3PKciE);
    return ((struct drb_foreign_object_ZTSPFiPvP7sqlite3PKciE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFiPvP7sqlite3PKciE_ToRuby(mrb_state *state, int (*value)(void *, sqlite3 *, const char *, int)) {
    struct drb_foreign_object_ZTSPFiPvP7sqlite3PKciE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiPvP7sqlite3PKciE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_17Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFiPvP7sqlite3PKciE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSP18sqlite3_index_info {
    drb_foreign_object_kind kind;
    sqlite3_index_info *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSP18sqlite3_index_info = {"sqlite3_index_info*", drb_free_foreign_object_indirect};
static sqlite3_index_info *drb_ffi__ZTSP18sqlite3_index_info_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3_index_infoPointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSP18sqlite3_index_info);
    return ((struct drb_foreign_object_ZTSP18sqlite3_index_info *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSP18sqlite3_index_info_ToRuby(mrb_state *state, sqlite3_index_info *value) {
    struct drb_foreign_object_ZTSP18sqlite3_index_info *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP18sqlite3_index_info));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3_index_infoPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSP18sqlite3_index_info);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPP13sqlite3_value {
    drb_foreign_object_kind kind;
    sqlite3_value **value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPP13sqlite3_value = {"sqlite3_value**", drb_free_foreign_object_indirect};
static sqlite3_value **drb_ffi__ZTSPP13sqlite3_value_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3_valuePointerPointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPP13sqlite3_value);
    return ((struct drb_foreign_object_ZTSPP13sqlite3_value *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPP13sqlite3_value_ToRuby(mrb_state *state, sqlite3_value **value) {
    struct drb_foreign_object_ZTSPP13sqlite3_value *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPP13sqlite3_value));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3_valuePointerPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPP13sqlite3_value);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFiP22sqlite3_rtree_geometryiPdPiE {
    drb_foreign_object_kind kind;
    int (*value)(sqlite3_rtree_geometry *, int, sqlite3_rtree_dbl *, int *);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFiP22sqlite3_rtree_geometryiPdPiE = {"Function_18*", drb_free_foreign_object_indirect};
static int (*drb_ffi__ZTSPFiP22sqlite3_rtree_geometryiPdPiE_FromRuby(mrb_state *state, mrb_value self))(sqlite3_rtree_geometry *, int, sqlite3_rtree_dbl *, int *) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_18Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFiP22sqlite3_rtree_geometryiPdPiE);
    return ((struct drb_foreign_object_ZTSPFiP22sqlite3_rtree_geometryiPdPiE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFiP22sqlite3_rtree_geometryiPdPiE_ToRuby(mrb_state *state, int (*value)(sqlite3_rtree_geometry *, int, sqlite3_rtree_dbl *, int *)) {
    struct drb_foreign_object_ZTSPFiP22sqlite3_rtree_geometryiPdPiE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP22sqlite3_rtree_geometryiPdPiE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_18Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFiP22sqlite3_rtree_geometryiPdPiE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFiP24sqlite3_rtree_query_infoE {
    drb_foreign_object_kind kind;
    int (*value)(sqlite3_rtree_query_info *);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFiP24sqlite3_rtree_query_infoE = {"Function_19*", drb_free_foreign_object_indirect};
static int (*drb_ffi__ZTSPFiP24sqlite3_rtree_query_infoE_FromRuby(mrb_state *state, mrb_value self))(sqlite3_rtree_query_info *) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_19Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFiP24sqlite3_rtree_query_infoE);
    return ((struct drb_foreign_object_ZTSPFiP24sqlite3_rtree_query_infoE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFiP24sqlite3_rtree_query_infoE_ToRuby(mrb_state *state, int (*value)(sqlite3_rtree_query_info *)) {
    struct drb_foreign_object_ZTSPFiP24sqlite3_rtree_query_infoE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP24sqlite3_rtree_query_infoE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_19Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFiP24sqlite3_rtree_query_infoE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTS12sqlite3_file {
    drb_foreign_object_kind kind;
    sqlite3_file value;
};
static mrb_data_type ForeignObjectType_ZTS12sqlite3_file = {"sqlite3_file", drb_free_foreign_object_indirect};
static sqlite3_file drb_ffi__ZTS12sqlite3_file_FromRuby(mrb_state *state, mrb_value self) {
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3_file");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTS12sqlite3_file);
    return ((struct drb_foreign_object_ZTS12sqlite3_file *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTS12sqlite3_file_ToRuby(mrb_state *state, sqlite3_file value) {
    struct drb_foreign_object_ZTS12sqlite3_file *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS12sqlite3_file));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_struct;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3_file");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTS12sqlite3_file);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTS14sqlite3_module {
    drb_foreign_object_kind kind;
    sqlite3_module value;
};
static mrb_data_type ForeignObjectType_ZTS14sqlite3_module = {"sqlite3_module", drb_free_foreign_object_indirect};
static sqlite3_module drb_ffi__ZTS14sqlite3_module_FromRuby(mrb_state *state, mrb_value self) {
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3_module");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTS14sqlite3_module);
    return ((struct drb_foreign_object_ZTS14sqlite3_module *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTS14sqlite3_module_ToRuby(mrb_state *state, sqlite3_module value) {
    struct drb_foreign_object_ZTS14sqlite3_module *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS14sqlite3_module));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_struct;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3_module");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTS14sqlite3_module);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTS11sqlite3_vfs {
    drb_foreign_object_kind kind;
    sqlite3_vfs value;
};
static mrb_data_type ForeignObjectType_ZTS11sqlite3_vfs = {"sqlite3_vfs", drb_free_foreign_object_indirect};
static sqlite3_vfs drb_ffi__ZTS11sqlite3_vfs_FromRuby(mrb_state *state, mrb_value self) {
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3_vfs");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTS11sqlite3_vfs);
    return ((struct drb_foreign_object_ZTS11sqlite3_vfs *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTS11sqlite3_vfs_ToRuby(mrb_state *state, sqlite3_vfs value) {
    struct drb_foreign_object_ZTS11sqlite3_vfs *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS11sqlite3_vfs));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_struct;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3_vfs");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTS11sqlite3_vfs);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTS18sqlite3_index_info {
    drb_foreign_object_kind kind;
    sqlite3_index_info value;
};
static mrb_data_type ForeignObjectType_ZTS18sqlite3_index_info = {"sqlite3_index_info", drb_free_foreign_object_indirect};
static sqlite3_index_info drb_ffi__ZTS18sqlite3_index_info_FromRuby(mrb_state *state, mrb_value self) {
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3_index_info");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTS18sqlite3_index_info);
    return ((struct drb_foreign_object_ZTS18sqlite3_index_info *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTS18sqlite3_index_info_ToRuby(mrb_state *state, sqlite3_index_info value) {
    struct drb_foreign_object_ZTS18sqlite3_index_info *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS18sqlite3_index_info));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_struct;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3_index_info");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTS18sqlite3_index_info);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSP18sqlite3_io_methods {
    drb_foreign_object_kind kind;
    struct sqlite3_io_methods *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSP18sqlite3_io_methods = {"sqlite3_io_methods*", drb_free_foreign_object_indirect};
static struct sqlite3_io_methods *drb_ffi__ZTSP18sqlite3_io_methods_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3_io_methodsPointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSP18sqlite3_io_methods);
    return ((struct drb_foreign_object_ZTSP18sqlite3_io_methods *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSP18sqlite3_io_methods_ToRuby(mrb_state *state, struct sqlite3_io_methods *value) {
    struct drb_foreign_object_ZTSP18sqlite3_io_methods *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP18sqlite3_io_methods));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3_io_methodsPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSP18sqlite3_io_methods);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFiP7sqlite3PviPKPKcPP12sqlite3_vtabPPcE {
    drb_foreign_object_kind kind;
    int (*value)(sqlite3 *, void *, int, const char *const *, sqlite3_vtab **, char **);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFiP7sqlite3PviPKPKcPP12sqlite3_vtabPPcE = {"Function_20*", drb_free_foreign_object_indirect};
static int (*drb_ffi__ZTSPFiP7sqlite3PviPKPKcPP12sqlite3_vtabPPcE_FromRuby(mrb_state *state, mrb_value self))(sqlite3 *, void *, int, const char *const *, sqlite3_vtab **, char **) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_20Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFiP7sqlite3PviPKPKcPP12sqlite3_vtabPPcE);
    return ((struct drb_foreign_object_ZTSPFiP7sqlite3PviPKPKcPP12sqlite3_vtabPPcE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFiP7sqlite3PviPKPKcPP12sqlite3_vtabPPcE_ToRuby(mrb_state *state, int (*value)(sqlite3 *, void *, int, const char *const *, sqlite3_vtab **, char **)) {
    struct drb_foreign_object_ZTSPFiP7sqlite3PviPKPKcPP12sqlite3_vtabPPcE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP7sqlite3PviPKPKcPP12sqlite3_vtabPPcE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_20Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFiP7sqlite3PviPKPKcPP12sqlite3_vtabPPcE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFiP12sqlite3_vtabP18sqlite3_index_infoE {
    drb_foreign_object_kind kind;
    int (*value)(sqlite3_vtab *, sqlite3_index_info *);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFiP12sqlite3_vtabP18sqlite3_index_infoE = {"Function_21*", drb_free_foreign_object_indirect};
static int (*drb_ffi__ZTSPFiP12sqlite3_vtabP18sqlite3_index_infoE_FromRuby(mrb_state *state, mrb_value self))(sqlite3_vtab *, sqlite3_index_info *) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_21Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFiP12sqlite3_vtabP18sqlite3_index_infoE);
    return ((struct drb_foreign_object_ZTSPFiP12sqlite3_vtabP18sqlite3_index_infoE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_vtabP18sqlite3_index_infoE_ToRuby(mrb_state *state, int (*value)(sqlite3_vtab *, sqlite3_index_info *)) {
    struct drb_foreign_object_ZTSPFiP12sqlite3_vtabP18sqlite3_index_infoE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP12sqlite3_vtabP18sqlite3_index_infoE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_21Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFiP12sqlite3_vtabP18sqlite3_index_infoE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFiP12sqlite3_vtabE {
    drb_foreign_object_kind kind;
    int (*value)(sqlite3_vtab *);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFiP12sqlite3_vtabE = {"Function_22*", drb_free_foreign_object_indirect};
static int (*drb_ffi__ZTSPFiP12sqlite3_vtabE_FromRuby(mrb_state *state, mrb_value self))(sqlite3_vtab *) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_22Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFiP12sqlite3_vtabE);
    return ((struct drb_foreign_object_ZTSPFiP12sqlite3_vtabE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_vtabE_ToRuby(mrb_state *state, int (*value)(sqlite3_vtab *)) {
    struct drb_foreign_object_ZTSPFiP12sqlite3_vtabE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP12sqlite3_vtabE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_22Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFiP12sqlite3_vtabE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFiP12sqlite3_vtabPP19sqlite3_vtab_cursorE {
    drb_foreign_object_kind kind;
    int (*value)(sqlite3_vtab *, sqlite3_vtab_cursor **);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFiP12sqlite3_vtabPP19sqlite3_vtab_cursorE = {"Function_23*", drb_free_foreign_object_indirect};
static int (*drb_ffi__ZTSPFiP12sqlite3_vtabPP19sqlite3_vtab_cursorE_FromRuby(mrb_state *state, mrb_value self))(sqlite3_vtab *, sqlite3_vtab_cursor **) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_23Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFiP12sqlite3_vtabPP19sqlite3_vtab_cursorE);
    return ((struct drb_foreign_object_ZTSPFiP12sqlite3_vtabPP19sqlite3_vtab_cursorE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_vtabPP19sqlite3_vtab_cursorE_ToRuby(mrb_state *state, int (*value)(sqlite3_vtab *, sqlite3_vtab_cursor **)) {
    struct drb_foreign_object_ZTSPFiP12sqlite3_vtabPP19sqlite3_vtab_cursorE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP12sqlite3_vtabPP19sqlite3_vtab_cursorE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_23Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFiP12sqlite3_vtabPP19sqlite3_vtab_cursorE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFiP19sqlite3_vtab_cursorE {
    drb_foreign_object_kind kind;
    int (*value)(sqlite3_vtab_cursor *);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFiP19sqlite3_vtab_cursorE = {"Function_24*", drb_free_foreign_object_indirect};
static int (*drb_ffi__ZTSPFiP19sqlite3_vtab_cursorE_FromRuby(mrb_state *state, mrb_value self))(sqlite3_vtab_cursor *) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_24Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFiP19sqlite3_vtab_cursorE);
    return ((struct drb_foreign_object_ZTSPFiP19sqlite3_vtab_cursorE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFiP19sqlite3_vtab_cursorE_ToRuby(mrb_state *state, int (*value)(sqlite3_vtab_cursor *)) {
    struct drb_foreign_object_ZTSPFiP19sqlite3_vtab_cursorE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP19sqlite3_vtab_cursorE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_24Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFiP19sqlite3_vtab_cursorE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFiP19sqlite3_vtab_cursoriPKciPP13sqlite3_valueE {
    drb_foreign_object_kind kind;
    int (*value)(sqlite3_vtab_cursor *, int, const char *, int, sqlite3_value **);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFiP19sqlite3_vtab_cursoriPKciPP13sqlite3_valueE = {"Function_25*", drb_free_foreign_object_indirect};
static int (*drb_ffi__ZTSPFiP19sqlite3_vtab_cursoriPKciPP13sqlite3_valueE_FromRuby(mrb_state *state, mrb_value self))(sqlite3_vtab_cursor *, int, const char *, int, sqlite3_value **) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_25Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFiP19sqlite3_vtab_cursoriPKciPP13sqlite3_valueE);
    return ((struct drb_foreign_object_ZTSPFiP19sqlite3_vtab_cursoriPKciPP13sqlite3_valueE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFiP19sqlite3_vtab_cursoriPKciPP13sqlite3_valueE_ToRuby(mrb_state *state, int (*value)(sqlite3_vtab_cursor *, int, const char *, int, sqlite3_value **)) {
    struct drb_foreign_object_ZTSPFiP19sqlite3_vtab_cursoriPKciPP13sqlite3_valueE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP19sqlite3_vtab_cursoriPKciPP13sqlite3_valueE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_25Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFiP19sqlite3_vtab_cursoriPKciPP13sqlite3_valueE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFiP19sqlite3_vtab_cursorP15sqlite3_contextiE {
    drb_foreign_object_kind kind;
    int (*value)(sqlite3_vtab_cursor *, sqlite3_context *, int);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFiP19sqlite3_vtab_cursorP15sqlite3_contextiE = {"Function_26*", drb_free_foreign_object_indirect};
static int (*drb_ffi__ZTSPFiP19sqlite3_vtab_cursorP15sqlite3_contextiE_FromRuby(mrb_state *state, mrb_value self))(sqlite3_vtab_cursor *, sqlite3_context *, int) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_26Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFiP19sqlite3_vtab_cursorP15sqlite3_contextiE);
    return ((struct drb_foreign_object_ZTSPFiP19sqlite3_vtab_cursorP15sqlite3_contextiE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFiP19sqlite3_vtab_cursorP15sqlite3_contextiE_ToRuby(mrb_state *state, int (*value)(sqlite3_vtab_cursor *, sqlite3_context *, int)) {
    struct drb_foreign_object_ZTSPFiP19sqlite3_vtab_cursorP15sqlite3_contextiE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP19sqlite3_vtab_cursorP15sqlite3_contextiE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_26Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFiP19sqlite3_vtab_cursorP15sqlite3_contextiE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFiP19sqlite3_vtab_cursorPxE {
    drb_foreign_object_kind kind;
    int (*value)(sqlite3_vtab_cursor *, sqlite3_int64 *);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFiP19sqlite3_vtab_cursorPxE = {"Function_27*", drb_free_foreign_object_indirect};
static int (*drb_ffi__ZTSPFiP19sqlite3_vtab_cursorPxE_FromRuby(mrb_state *state, mrb_value self))(sqlite3_vtab_cursor *, sqlite3_int64 *) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_27Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFiP19sqlite3_vtab_cursorPxE);
    return ((struct drb_foreign_object_ZTSPFiP19sqlite3_vtab_cursorPxE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFiP19sqlite3_vtab_cursorPxE_ToRuby(mrb_state *state, int (*value)(sqlite3_vtab_cursor *, sqlite3_int64 *)) {
    struct drb_foreign_object_ZTSPFiP19sqlite3_vtab_cursorPxE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP19sqlite3_vtab_cursorPxE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_27Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFiP19sqlite3_vtab_cursorPxE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFiP12sqlite3_vtabiPP13sqlite3_valuePxE {
    drb_foreign_object_kind kind;
    int (*value)(sqlite3_vtab *, int, sqlite3_value **, sqlite3_int64 *);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFiP12sqlite3_vtabiPP13sqlite3_valuePxE = {"Function_28*", drb_free_foreign_object_indirect};
static int (*drb_ffi__ZTSPFiP12sqlite3_vtabiPP13sqlite3_valuePxE_FromRuby(mrb_state *state, mrb_value self))(sqlite3_vtab *, int, sqlite3_value **, sqlite3_int64 *) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_28Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFiP12sqlite3_vtabiPP13sqlite3_valuePxE);
    return ((struct drb_foreign_object_ZTSPFiP12sqlite3_vtabiPP13sqlite3_valuePxE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_vtabiPP13sqlite3_valuePxE_ToRuby(mrb_state *state, int (*value)(sqlite3_vtab *, int, sqlite3_value **, sqlite3_int64 *)) {
    struct drb_foreign_object_ZTSPFiP12sqlite3_vtabiPP13sqlite3_valuePxE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP12sqlite3_vtabiPP13sqlite3_valuePxE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_28Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFiP12sqlite3_vtabiPP13sqlite3_valuePxE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFiP12sqlite3_vtabiPKcPPFvP15sqlite3_contextiPP13sqlite3_valueEPPvE {
    drb_foreign_object_kind kind;
    int (*value)(sqlite3_vtab *, int, const char *, void (**)(sqlite3_context *, int, sqlite3_value **), void **);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFiP12sqlite3_vtabiPKcPPFvP15sqlite3_contextiPP13sqlite3_valueEPPvE = {"Function_29*", drb_free_foreign_object_indirect};
static int (*drb_ffi__ZTSPFiP12sqlite3_vtabiPKcPPFvP15sqlite3_contextiPP13sqlite3_valueEPPvE_FromRuby(mrb_state *state, mrb_value self))(sqlite3_vtab *, int, const char *, void (**)(sqlite3_context *, int, sqlite3_value **), void **) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_29Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFiP12sqlite3_vtabiPKcPPFvP15sqlite3_contextiPP13sqlite3_valueEPPvE);
    return ((struct drb_foreign_object_ZTSPFiP12sqlite3_vtabiPKcPPFvP15sqlite3_contextiPP13sqlite3_valueEPPvE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_vtabiPKcPPFvP15sqlite3_contextiPP13sqlite3_valueEPPvE_ToRuby(mrb_state *state, int (*value)(sqlite3_vtab *, int, const char *, void (**)(sqlite3_context *, int, sqlite3_value **), void **)) {
    struct drb_foreign_object_ZTSPFiP12sqlite3_vtabiPKcPPFvP15sqlite3_contextiPP13sqlite3_valueEPPvE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP12sqlite3_vtabiPKcPPFvP15sqlite3_contextiPP13sqlite3_valueEPPvE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_29Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFiP12sqlite3_vtabiPKcPPFvP15sqlite3_contextiPP13sqlite3_valueEPPvE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFiP12sqlite3_vtabPKcE {
    drb_foreign_object_kind kind;
    int (*value)(sqlite3_vtab *, const char *);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFiP12sqlite3_vtabPKcE = {"Function_30*", drb_free_foreign_object_indirect};
static int (*drb_ffi__ZTSPFiP12sqlite3_vtabPKcE_FromRuby(mrb_state *state, mrb_value self))(sqlite3_vtab *, const char *) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_30Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFiP12sqlite3_vtabPKcE);
    return ((struct drb_foreign_object_ZTSPFiP12sqlite3_vtabPKcE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_vtabPKcE_ToRuby(mrb_state *state, int (*value)(sqlite3_vtab *, const char *)) {
    struct drb_foreign_object_ZTSPFiP12sqlite3_vtabPKcE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP12sqlite3_vtabPKcE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_30Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFiP12sqlite3_vtabPKcE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFiP12sqlite3_vtabiE {
    drb_foreign_object_kind kind;
    int (*value)(sqlite3_vtab *, int);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFiP12sqlite3_vtabiE = {"Function_31*", drb_free_foreign_object_indirect};
static int (*drb_ffi__ZTSPFiP12sqlite3_vtabiE_FromRuby(mrb_state *state, mrb_value self))(sqlite3_vtab *, int) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_31Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFiP12sqlite3_vtabiE);
    return ((struct drb_foreign_object_ZTSPFiP12sqlite3_vtabiE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_vtabiE_ToRuby(mrb_state *state, int (*value)(sqlite3_vtab *, int)) {
    struct drb_foreign_object_ZTSPFiP12sqlite3_vtabiE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP12sqlite3_vtabiE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_31Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFiP12sqlite3_vtabiE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFiPKcE {
    drb_foreign_object_kind kind;
    int (*value)(const char *);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFiPKcE = {"Function_32*", drb_free_foreign_object_indirect};
static int (*drb_ffi__ZTSPFiPKcE_FromRuby(mrb_state *state, mrb_value self))(const char *) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_32Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFiPKcE);
    return ((struct drb_foreign_object_ZTSPFiPKcE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFiPKcE_ToRuby(mrb_state *state, int (*value)(const char *)) {
    struct drb_foreign_object_ZTSPFiPKcE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiPKcE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_32Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFiPKcE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFiP11sqlite3_vfsPKcP12sqlite3_fileiPiE {
    drb_foreign_object_kind kind;
    int (*value)(sqlite3_vfs *, const char *, sqlite3_file *, int, int *);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFiP11sqlite3_vfsPKcP12sqlite3_fileiPiE = {"Function_33*", drb_free_foreign_object_indirect};
static int (*drb_ffi__ZTSPFiP11sqlite3_vfsPKcP12sqlite3_fileiPiE_FromRuby(mrb_state *state, mrb_value self))(sqlite3_vfs *, const char *, sqlite3_file *, int, int *) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_33Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFiP11sqlite3_vfsPKcP12sqlite3_fileiPiE);
    return ((struct drb_foreign_object_ZTSPFiP11sqlite3_vfsPKcP12sqlite3_fileiPiE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFiP11sqlite3_vfsPKcP12sqlite3_fileiPiE_ToRuby(mrb_state *state, int (*value)(sqlite3_vfs *, const char *, sqlite3_file *, int, int *)) {
    struct drb_foreign_object_ZTSPFiP11sqlite3_vfsPKcP12sqlite3_fileiPiE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP11sqlite3_vfsPKcP12sqlite3_fileiPiE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_33Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFiP11sqlite3_vfsPKcP12sqlite3_fileiPiE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFiP11sqlite3_vfsPKciE {
    drb_foreign_object_kind kind;
    int (*value)(sqlite3_vfs *, const char *, int);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFiP11sqlite3_vfsPKciE = {"Function_34*", drb_free_foreign_object_indirect};
static int (*drb_ffi__ZTSPFiP11sqlite3_vfsPKciE_FromRuby(mrb_state *state, mrb_value self))(sqlite3_vfs *, const char *, int) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_34Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFiP11sqlite3_vfsPKciE);
    return ((struct drb_foreign_object_ZTSPFiP11sqlite3_vfsPKciE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFiP11sqlite3_vfsPKciE_ToRuby(mrb_state *state, int (*value)(sqlite3_vfs *, const char *, int)) {
    struct drb_foreign_object_ZTSPFiP11sqlite3_vfsPKciE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP11sqlite3_vfsPKciE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_34Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFiP11sqlite3_vfsPKciE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFiP11sqlite3_vfsPKciPiE {
    drb_foreign_object_kind kind;
    int (*value)(sqlite3_vfs *, const char *, int, int *);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFiP11sqlite3_vfsPKciPiE = {"Function_35*", drb_free_foreign_object_indirect};
static int (*drb_ffi__ZTSPFiP11sqlite3_vfsPKciPiE_FromRuby(mrb_state *state, mrb_value self))(sqlite3_vfs *, const char *, int, int *) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_35Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFiP11sqlite3_vfsPKciPiE);
    return ((struct drb_foreign_object_ZTSPFiP11sqlite3_vfsPKciPiE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFiP11sqlite3_vfsPKciPiE_ToRuby(mrb_state *state, int (*value)(sqlite3_vfs *, const char *, int, int *)) {
    struct drb_foreign_object_ZTSPFiP11sqlite3_vfsPKciPiE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP11sqlite3_vfsPKciPiE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_35Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFiP11sqlite3_vfsPKciPiE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFiP11sqlite3_vfsPKciPcE {
    drb_foreign_object_kind kind;
    int (*value)(sqlite3_vfs *, const char *, int, char *);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFiP11sqlite3_vfsPKciPcE = {"Function_36*", drb_free_foreign_object_indirect};
static int (*drb_ffi__ZTSPFiP11sqlite3_vfsPKciPcE_FromRuby(mrb_state *state, mrb_value self))(sqlite3_vfs *, const char *, int, char *) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_36Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFiP11sqlite3_vfsPKciPcE);
    return ((struct drb_foreign_object_ZTSPFiP11sqlite3_vfsPKciPcE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFiP11sqlite3_vfsPKciPcE_ToRuby(mrb_state *state, int (*value)(sqlite3_vfs *, const char *, int, char *)) {
    struct drb_foreign_object_ZTSPFiP11sqlite3_vfsPKciPcE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP11sqlite3_vfsPKciPcE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_36Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFiP11sqlite3_vfsPKciPcE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFPvP11sqlite3_vfsPKcE {
    drb_foreign_object_kind kind;
    void *(*value)(sqlite3_vfs *, const char *);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFPvP11sqlite3_vfsPKcE = {"Function_37*", drb_free_foreign_object_indirect};
static void *(*drb_ffi__ZTSPFPvP11sqlite3_vfsPKcE_FromRuby(mrb_state *state, mrb_value self))(sqlite3_vfs *, const char *) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_37Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFPvP11sqlite3_vfsPKcE);
    return ((struct drb_foreign_object_ZTSPFPvP11sqlite3_vfsPKcE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFPvP11sqlite3_vfsPKcE_ToRuby(mrb_state *state, void *(*value)(sqlite3_vfs *, const char *)) {
    struct drb_foreign_object_ZTSPFPvP11sqlite3_vfsPKcE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFPvP11sqlite3_vfsPKcE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_37Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFPvP11sqlite3_vfsPKcE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFvP11sqlite3_vfsiPcE {
    drb_foreign_object_kind kind;
    void (*value)(sqlite3_vfs *, int, char *);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFvP11sqlite3_vfsiPcE = {"Function_38*", drb_free_foreign_object_indirect};
static void (*drb_ffi__ZTSPFvP11sqlite3_vfsiPcE_FromRuby(mrb_state *state, mrb_value self))(sqlite3_vfs *, int, char *) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_38Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFvP11sqlite3_vfsiPcE);
    return ((struct drb_foreign_object_ZTSPFvP11sqlite3_vfsiPcE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFvP11sqlite3_vfsiPcE_ToRuby(mrb_state *state, void (*value)(sqlite3_vfs *, int, char *)) {
    struct drb_foreign_object_ZTSPFvP11sqlite3_vfsiPcE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFvP11sqlite3_vfsiPcE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_38Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFvP11sqlite3_vfsiPcE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFPFvvEP11sqlite3_vfsPvPKcE {
    drb_foreign_object_kind kind;
    void (*(*value)(sqlite3_vfs *, void *, const char *))(void);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFPFvvEP11sqlite3_vfsPvPKcE = {"Function_39*", drb_free_foreign_object_indirect};
static void (*(*drb_ffi__ZTSPFPFvvEP11sqlite3_vfsPvPKcE_FromRuby(mrb_state *state, mrb_value self))(sqlite3_vfs *, void *, const char *))(void) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_39Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFPFvvEP11sqlite3_vfsPvPKcE);
    return ((struct drb_foreign_object_ZTSPFPFvvEP11sqlite3_vfsPvPKcE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFPFvvEP11sqlite3_vfsPvPKcE_ToRuby(mrb_state *state, void (*(*value)(sqlite3_vfs *, void *, const char *))(void)) {
    struct drb_foreign_object_ZTSPFPFvvEP11sqlite3_vfsPvPKcE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFPFvvEP11sqlite3_vfsPvPKcE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_39Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFPFvvEP11sqlite3_vfsPvPKcE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFvP11sqlite3_vfsPvE {
    drb_foreign_object_kind kind;
    void (*value)(sqlite3_vfs *, void *);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFvP11sqlite3_vfsPvE = {"Function_40*", drb_free_foreign_object_indirect};
static void (*drb_ffi__ZTSPFvP11sqlite3_vfsPvE_FromRuby(mrb_state *state, mrb_value self))(sqlite3_vfs *, void *) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_40Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFvP11sqlite3_vfsPvE);
    return ((struct drb_foreign_object_ZTSPFvP11sqlite3_vfsPvE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFvP11sqlite3_vfsPvE_ToRuby(mrb_state *state, void (*value)(sqlite3_vfs *, void *)) {
    struct drb_foreign_object_ZTSPFvP11sqlite3_vfsPvE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFvP11sqlite3_vfsPvE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_40Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFvP11sqlite3_vfsPvE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFiP11sqlite3_vfsiPcE {
    drb_foreign_object_kind kind;
    int (*value)(sqlite3_vfs *, int, char *);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFiP11sqlite3_vfsiPcE = {"Function_41*", drb_free_foreign_object_indirect};
static int (*drb_ffi__ZTSPFiP11sqlite3_vfsiPcE_FromRuby(mrb_state *state, mrb_value self))(sqlite3_vfs *, int, char *) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_41Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFiP11sqlite3_vfsiPcE);
    return ((struct drb_foreign_object_ZTSPFiP11sqlite3_vfsiPcE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFiP11sqlite3_vfsiPcE_ToRuby(mrb_state *state, int (*value)(sqlite3_vfs *, int, char *)) {
    struct drb_foreign_object_ZTSPFiP11sqlite3_vfsiPcE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP11sqlite3_vfsiPcE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_41Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFiP11sqlite3_vfsiPcE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFiP11sqlite3_vfsiE {
    drb_foreign_object_kind kind;
    int (*value)(sqlite3_vfs *, int);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFiP11sqlite3_vfsiE = {"Function_42*", drb_free_foreign_object_indirect};
static int (*drb_ffi__ZTSPFiP11sqlite3_vfsiE_FromRuby(mrb_state *state, mrb_value self))(sqlite3_vfs *, int) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_42Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFiP11sqlite3_vfsiE);
    return ((struct drb_foreign_object_ZTSPFiP11sqlite3_vfsiE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFiP11sqlite3_vfsiE_ToRuby(mrb_state *state, int (*value)(sqlite3_vfs *, int)) {
    struct drb_foreign_object_ZTSPFiP11sqlite3_vfsiE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP11sqlite3_vfsiE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_42Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFiP11sqlite3_vfsiE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFiP11sqlite3_vfsPdE {
    drb_foreign_object_kind kind;
    int (*value)(sqlite3_vfs *, double *);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFiP11sqlite3_vfsPdE = {"Function_43*", drb_free_foreign_object_indirect};
static int (*drb_ffi__ZTSPFiP11sqlite3_vfsPdE_FromRuby(mrb_state *state, mrb_value self))(sqlite3_vfs *, double *) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_43Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFiP11sqlite3_vfsPdE);
    return ((struct drb_foreign_object_ZTSPFiP11sqlite3_vfsPdE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFiP11sqlite3_vfsPdE_ToRuby(mrb_state *state, int (*value)(sqlite3_vfs *, double *)) {
    struct drb_foreign_object_ZTSPFiP11sqlite3_vfsPdE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP11sqlite3_vfsPdE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_43Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFiP11sqlite3_vfsPdE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFiP11sqlite3_vfsPxE {
    drb_foreign_object_kind kind;
    int (*value)(sqlite3_vfs *, sqlite3_int64 *);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFiP11sqlite3_vfsPxE = {"Function_44*", drb_free_foreign_object_indirect};
static int (*drb_ffi__ZTSPFiP11sqlite3_vfsPxE_FromRuby(mrb_state *state, mrb_value self))(sqlite3_vfs *, sqlite3_int64 *) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_44Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFiP11sqlite3_vfsPxE);
    return ((struct drb_foreign_object_ZTSPFiP11sqlite3_vfsPxE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFiP11sqlite3_vfsPxE_ToRuby(mrb_state *state, int (*value)(sqlite3_vfs *, sqlite3_int64 *)) {
    struct drb_foreign_object_ZTSPFiP11sqlite3_vfsPxE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP11sqlite3_vfsPxE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_44Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFiP11sqlite3_vfsPxE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFiP11sqlite3_vfsPKcPFvvEE {
    drb_foreign_object_kind kind;
    int (*value)(sqlite3_vfs *, const char *, sqlite3_syscall_ptr);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFiP11sqlite3_vfsPKcPFvvEE = {"Function_45*", drb_free_foreign_object_indirect};
static int (*drb_ffi__ZTSPFiP11sqlite3_vfsPKcPFvvEE_FromRuby(mrb_state *state, mrb_value self))(sqlite3_vfs *, const char *, sqlite3_syscall_ptr) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_45Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFiP11sqlite3_vfsPKcPFvvEE);
    return ((struct drb_foreign_object_ZTSPFiP11sqlite3_vfsPKcPFvvEE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFiP11sqlite3_vfsPKcPFvvEE_ToRuby(mrb_state *state, int (*value)(sqlite3_vfs *, const char *, sqlite3_syscall_ptr)) {
    struct drb_foreign_object_ZTSPFiP11sqlite3_vfsPKcPFvvEE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP11sqlite3_vfsPKcPFvvEE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_45Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFiP11sqlite3_vfsPKcPFvvEE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFPFvvEP11sqlite3_vfsPKcE {
    drb_foreign_object_kind kind;
    sqlite3_syscall_ptr (*value)(sqlite3_vfs *, const char *);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFPFvvEP11sqlite3_vfsPKcE = {"Function_46*", drb_free_foreign_object_indirect};
static sqlite3_syscall_ptr (*drb_ffi__ZTSPFPFvvEP11sqlite3_vfsPKcE_FromRuby(mrb_state *state, mrb_value self))(sqlite3_vfs *, const char *) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_46Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFPFvvEP11sqlite3_vfsPKcE);
    return ((struct drb_foreign_object_ZTSPFPFvvEP11sqlite3_vfsPKcE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFPFvvEP11sqlite3_vfsPKcE_ToRuby(mrb_state *state, sqlite3_syscall_ptr (*value)(sqlite3_vfs *, const char *)) {
    struct drb_foreign_object_ZTSPFPFvvEP11sqlite3_vfsPKcE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFPFvvEP11sqlite3_vfsPKcE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_46Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFPFvvEP11sqlite3_vfsPKcE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFPKcP11sqlite3_vfsS0_E {
    drb_foreign_object_kind kind;
    const char *(*value)(sqlite3_vfs *, const char *);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFPKcP11sqlite3_vfsS0_E = {"Function_47*", drb_free_foreign_object_indirect};
static const char *(*drb_ffi__ZTSPFPKcP11sqlite3_vfsS0_E_FromRuby(mrb_state *state, mrb_value self))(sqlite3_vfs *, const char *) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_47Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFPKcP11sqlite3_vfsS0_E);
    return ((struct drb_foreign_object_ZTSPFPKcP11sqlite3_vfsS0_E *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFPKcP11sqlite3_vfsS0_E_ToRuby(mrb_state *state, const char *(*value)(sqlite3_vfs *, const char *)) {
    struct drb_foreign_object_ZTSPFPKcP11sqlite3_vfsS0_E *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFPKcP11sqlite3_vfsS0_E));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_47Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFPKcP11sqlite3_vfsS0_E);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSP24sqlite3_index_constraint {
    drb_foreign_object_kind kind;
    struct sqlite3_index_constraint *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSP24sqlite3_index_constraint = {"sqlite3_index_constraint*", drb_free_foreign_object_indirect};
static struct sqlite3_index_constraint *drb_ffi__ZTSP24sqlite3_index_constraint_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3_index_constraintPointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSP24sqlite3_index_constraint);
    return ((struct drb_foreign_object_ZTSP24sqlite3_index_constraint *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSP24sqlite3_index_constraint_ToRuby(mrb_state *state, struct sqlite3_index_constraint *value) {
    struct drb_foreign_object_ZTSP24sqlite3_index_constraint *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP24sqlite3_index_constraint));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3_index_constraintPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSP24sqlite3_index_constraint);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSP21sqlite3_index_orderby {
    drb_foreign_object_kind kind;
    struct sqlite3_index_orderby *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSP21sqlite3_index_orderby = {"sqlite3_index_orderby*", drb_free_foreign_object_indirect};
static struct sqlite3_index_orderby *drb_ffi__ZTSP21sqlite3_index_orderby_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3_index_orderbyPointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSP21sqlite3_index_orderby);
    return ((struct drb_foreign_object_ZTSP21sqlite3_index_orderby *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSP21sqlite3_index_orderby_ToRuby(mrb_state *state, struct sqlite3_index_orderby *value) {
    struct drb_foreign_object_ZTSP21sqlite3_index_orderby *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP21sqlite3_index_orderby));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3_index_orderbyPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSP21sqlite3_index_orderby);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSP30sqlite3_index_constraint_usage {
    drb_foreign_object_kind kind;
    struct sqlite3_index_constraint_usage *value;
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSP30sqlite3_index_constraint_usage = {"sqlite3_index_constraint_usage*", drb_free_foreign_object_indirect};
static struct sqlite3_index_constraint_usage *drb_ffi__ZTSP30sqlite3_index_constraint_usage_FromRuby(mrb_state *state, mrb_value self) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3_index_constraint_usagePointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSP30sqlite3_index_constraint_usage);
    return ((struct drb_foreign_object_ZTSP30sqlite3_index_constraint_usage *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSP30sqlite3_index_constraint_usage_ToRuby(mrb_state *state, struct sqlite3_index_constraint_usage *value) {
    struct drb_foreign_object_ZTSP30sqlite3_index_constraint_usage *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP30sqlite3_index_constraint_usage));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3_index_constraint_usagePointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSP30sqlite3_index_constraint_usage);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTS18sqlite3_io_methods {
    drb_foreign_object_kind kind;
    struct sqlite3_io_methods value;
};
static mrb_data_type ForeignObjectType_ZTS18sqlite3_io_methods = {"sqlite3_io_methods", drb_free_foreign_object_indirect};
static struct sqlite3_io_methods drb_ffi__ZTS18sqlite3_io_methods_FromRuby(mrb_state *state, mrb_value self) {
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3_io_methods");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTS18sqlite3_io_methods);
    return ((struct drb_foreign_object_ZTS18sqlite3_io_methods *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTS18sqlite3_io_methods_ToRuby(mrb_state *state, struct sqlite3_io_methods value) {
    struct drb_foreign_object_ZTS18sqlite3_io_methods *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS18sqlite3_io_methods));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_struct;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3_io_methods");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTS18sqlite3_io_methods);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTS24sqlite3_index_constraint {
    drb_foreign_object_kind kind;
    struct sqlite3_index_constraint value;
};
static mrb_data_type ForeignObjectType_ZTS24sqlite3_index_constraint = {"sqlite3_index_constraint", drb_free_foreign_object_indirect};
static struct sqlite3_index_constraint drb_ffi__ZTS24sqlite3_index_constraint_FromRuby(mrb_state *state, mrb_value self) {
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3_index_constraint");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTS24sqlite3_index_constraint);
    return ((struct drb_foreign_object_ZTS24sqlite3_index_constraint *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTS24sqlite3_index_constraint_ToRuby(mrb_state *state, struct sqlite3_index_constraint value) {
    struct drb_foreign_object_ZTS24sqlite3_index_constraint *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS24sqlite3_index_constraint));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_struct;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3_index_constraint");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTS24sqlite3_index_constraint);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTS21sqlite3_index_orderby {
    drb_foreign_object_kind kind;
    struct sqlite3_index_orderby value;
};
static mrb_data_type ForeignObjectType_ZTS21sqlite3_index_orderby = {"sqlite3_index_orderby", drb_free_foreign_object_indirect};
static struct sqlite3_index_orderby drb_ffi__ZTS21sqlite3_index_orderby_FromRuby(mrb_state *state, mrb_value self) {
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3_index_orderby");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTS21sqlite3_index_orderby);
    return ((struct drb_foreign_object_ZTS21sqlite3_index_orderby *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTS21sqlite3_index_orderby_ToRuby(mrb_state *state, struct sqlite3_index_orderby value) {
    struct drb_foreign_object_ZTS21sqlite3_index_orderby *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS21sqlite3_index_orderby));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_struct;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3_index_orderby");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTS21sqlite3_index_orderby);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTS30sqlite3_index_constraint_usage {
    drb_foreign_object_kind kind;
    struct sqlite3_index_constraint_usage value;
};
static mrb_data_type ForeignObjectType_ZTS30sqlite3_index_constraint_usage = {"sqlite3_index_constraint_usage", drb_free_foreign_object_indirect};
static struct sqlite3_index_constraint_usage drb_ffi__ZTS30sqlite3_index_constraint_usage_FromRuby(mrb_state *state, mrb_value self) {
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3_index_constraint_usage");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTS30sqlite3_index_constraint_usage);
    return ((struct drb_foreign_object_ZTS30sqlite3_index_constraint_usage *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTS30sqlite3_index_constraint_usage_ToRuby(mrb_state *state, struct sqlite3_index_constraint_usage value) {
    struct drb_foreign_object_ZTS30sqlite3_index_constraint_usage *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS30sqlite3_index_constraint_usage));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_struct;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3_index_constraint_usage");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTS30sqlite3_index_constraint_usage);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFiP12sqlite3_fileE {
    drb_foreign_object_kind kind;
    int (*value)(sqlite3_file *);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFiP12sqlite3_fileE = {"Function_48*", drb_free_foreign_object_indirect};
static int (*drb_ffi__ZTSPFiP12sqlite3_fileE_FromRuby(mrb_state *state, mrb_value self))(sqlite3_file *) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_48Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFiP12sqlite3_fileE);
    return ((struct drb_foreign_object_ZTSPFiP12sqlite3_fileE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_fileE_ToRuby(mrb_state *state, int (*value)(sqlite3_file *)) {
    struct drb_foreign_object_ZTSPFiP12sqlite3_fileE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP12sqlite3_fileE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_48Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFiP12sqlite3_fileE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFiP12sqlite3_filePvixE {
    drb_foreign_object_kind kind;
    int (*value)(sqlite3_file *, void *, int, sqlite3_int64);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFiP12sqlite3_filePvixE = {"Function_49*", drb_free_foreign_object_indirect};
static int (*drb_ffi__ZTSPFiP12sqlite3_filePvixE_FromRuby(mrb_state *state, mrb_value self))(sqlite3_file *, void *, int, sqlite3_int64) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_49Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFiP12sqlite3_filePvixE);
    return ((struct drb_foreign_object_ZTSPFiP12sqlite3_filePvixE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_filePvixE_ToRuby(mrb_state *state, int (*value)(sqlite3_file *, void *, int, sqlite3_int64)) {
    struct drb_foreign_object_ZTSPFiP12sqlite3_filePvixE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP12sqlite3_filePvixE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_49Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFiP12sqlite3_filePvixE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFiP12sqlite3_filePKvixE {
    drb_foreign_object_kind kind;
    int (*value)(sqlite3_file *, const void *, int, sqlite3_int64);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFiP12sqlite3_filePKvixE = {"Function_50*", drb_free_foreign_object_indirect};
static int (*drb_ffi__ZTSPFiP12sqlite3_filePKvixE_FromRuby(mrb_state *state, mrb_value self))(sqlite3_file *, const void *, int, sqlite3_int64) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_50Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFiP12sqlite3_filePKvixE);
    return ((struct drb_foreign_object_ZTSPFiP12sqlite3_filePKvixE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_filePKvixE_ToRuby(mrb_state *state, int (*value)(sqlite3_file *, const void *, int, sqlite3_int64)) {
    struct drb_foreign_object_ZTSPFiP12sqlite3_filePKvixE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP12sqlite3_filePKvixE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_50Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFiP12sqlite3_filePKvixE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFiP12sqlite3_filexE {
    drb_foreign_object_kind kind;
    int (*value)(sqlite3_file *, sqlite3_int64);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFiP12sqlite3_filexE = {"Function_51*", drb_free_foreign_object_indirect};
static int (*drb_ffi__ZTSPFiP12sqlite3_filexE_FromRuby(mrb_state *state, mrb_value self))(sqlite3_file *, sqlite3_int64) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_51Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFiP12sqlite3_filexE);
    return ((struct drb_foreign_object_ZTSPFiP12sqlite3_filexE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_filexE_ToRuby(mrb_state *state, int (*value)(sqlite3_file *, sqlite3_int64)) {
    struct drb_foreign_object_ZTSPFiP12sqlite3_filexE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP12sqlite3_filexE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_51Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFiP12sqlite3_filexE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFiP12sqlite3_fileiE {
    drb_foreign_object_kind kind;
    int (*value)(sqlite3_file *, int);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFiP12sqlite3_fileiE = {"Function_52*", drb_free_foreign_object_indirect};
static int (*drb_ffi__ZTSPFiP12sqlite3_fileiE_FromRuby(mrb_state *state, mrb_value self))(sqlite3_file *, int) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_52Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFiP12sqlite3_fileiE);
    return ((struct drb_foreign_object_ZTSPFiP12sqlite3_fileiE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_fileiE_ToRuby(mrb_state *state, int (*value)(sqlite3_file *, int)) {
    struct drb_foreign_object_ZTSPFiP12sqlite3_fileiE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP12sqlite3_fileiE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_52Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFiP12sqlite3_fileiE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFiP12sqlite3_filePxE {
    drb_foreign_object_kind kind;
    int (*value)(sqlite3_file *, sqlite3_int64 *);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFiP12sqlite3_filePxE = {"Function_53*", drb_free_foreign_object_indirect};
static int (*drb_ffi__ZTSPFiP12sqlite3_filePxE_FromRuby(mrb_state *state, mrb_value self))(sqlite3_file *, sqlite3_int64 *) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_53Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFiP12sqlite3_filePxE);
    return ((struct drb_foreign_object_ZTSPFiP12sqlite3_filePxE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_filePxE_ToRuby(mrb_state *state, int (*value)(sqlite3_file *, sqlite3_int64 *)) {
    struct drb_foreign_object_ZTSPFiP12sqlite3_filePxE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP12sqlite3_filePxE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_53Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFiP12sqlite3_filePxE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFiP12sqlite3_filePiE {
    drb_foreign_object_kind kind;
    int (*value)(sqlite3_file *, int *);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFiP12sqlite3_filePiE = {"Function_54*", drb_free_foreign_object_indirect};
static int (*drb_ffi__ZTSPFiP12sqlite3_filePiE_FromRuby(mrb_state *state, mrb_value self))(sqlite3_file *, int *) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_54Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFiP12sqlite3_filePiE);
    return ((struct drb_foreign_object_ZTSPFiP12sqlite3_filePiE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_filePiE_ToRuby(mrb_state *state, int (*value)(sqlite3_file *, int *)) {
    struct drb_foreign_object_ZTSPFiP12sqlite3_filePiE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP12sqlite3_filePiE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_54Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFiP12sqlite3_filePiE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFiP12sqlite3_fileiPvE {
    drb_foreign_object_kind kind;
    int (*value)(sqlite3_file *, int, void *);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFiP12sqlite3_fileiPvE = {"Function_55*", drb_free_foreign_object_indirect};
static int (*drb_ffi__ZTSPFiP12sqlite3_fileiPvE_FromRuby(mrb_state *state, mrb_value self))(sqlite3_file *, int, void *) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_55Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFiP12sqlite3_fileiPvE);
    return ((struct drb_foreign_object_ZTSPFiP12sqlite3_fileiPvE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_fileiPvE_ToRuby(mrb_state *state, int (*value)(sqlite3_file *, int, void *)) {
    struct drb_foreign_object_ZTSPFiP12sqlite3_fileiPvE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP12sqlite3_fileiPvE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_55Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFiP12sqlite3_fileiPvE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFiP12sqlite3_fileiiiPPVvE {
    drb_foreign_object_kind kind;
    int (*value)(sqlite3_file *, int, int, int, volatile void **);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFiP12sqlite3_fileiiiPPVvE = {"Function_56*", drb_free_foreign_object_indirect};
static int (*drb_ffi__ZTSPFiP12sqlite3_fileiiiPPVvE_FromRuby(mrb_state *state, mrb_value self))(sqlite3_file *, int, int, int, volatile void **) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_56Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFiP12sqlite3_fileiiiPPVvE);
    return ((struct drb_foreign_object_ZTSPFiP12sqlite3_fileiiiPPVvE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_fileiiiPPVvE_ToRuby(mrb_state *state, int (*value)(sqlite3_file *, int, int, int, volatile void **)) {
    struct drb_foreign_object_ZTSPFiP12sqlite3_fileiiiPPVvE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP12sqlite3_fileiiiPPVvE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_56Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFiP12sqlite3_fileiiiPPVvE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFiP12sqlite3_fileiiiE {
    drb_foreign_object_kind kind;
    int (*value)(sqlite3_file *, int, int, int);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFiP12sqlite3_fileiiiE = {"Function_57*", drb_free_foreign_object_indirect};
static int (*drb_ffi__ZTSPFiP12sqlite3_fileiiiE_FromRuby(mrb_state *state, mrb_value self))(sqlite3_file *, int, int, int) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_57Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFiP12sqlite3_fileiiiE);
    return ((struct drb_foreign_object_ZTSPFiP12sqlite3_fileiiiE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_fileiiiE_ToRuby(mrb_state *state, int (*value)(sqlite3_file *, int, int, int)) {
    struct drb_foreign_object_ZTSPFiP12sqlite3_fileiiiE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP12sqlite3_fileiiiE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_57Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFiP12sqlite3_fileiiiE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFvP12sqlite3_fileE {
    drb_foreign_object_kind kind;
    void (*value)(sqlite3_file *);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFvP12sqlite3_fileE = {"Function_58*", drb_free_foreign_object_indirect};
static void (*drb_ffi__ZTSPFvP12sqlite3_fileE_FromRuby(mrb_state *state, mrb_value self))(sqlite3_file *) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_58Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFvP12sqlite3_fileE);
    return ((struct drb_foreign_object_ZTSPFvP12sqlite3_fileE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFvP12sqlite3_fileE_ToRuby(mrb_state *state, void (*value)(sqlite3_file *)) {
    struct drb_foreign_object_ZTSPFvP12sqlite3_fileE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFvP12sqlite3_fileE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_58Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFvP12sqlite3_fileE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFiP12sqlite3_filexiPPvE {
    drb_foreign_object_kind kind;
    int (*value)(sqlite3_file *, sqlite3_int64, int, void **);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFiP12sqlite3_filexiPPvE = {"Function_59*", drb_free_foreign_object_indirect};
static int (*drb_ffi__ZTSPFiP12sqlite3_filexiPPvE_FromRuby(mrb_state *state, mrb_value self))(sqlite3_file *, sqlite3_int64, int, void **) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_59Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFiP12sqlite3_filexiPPvE);
    return ((struct drb_foreign_object_ZTSPFiP12sqlite3_filexiPPvE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_filexiPPvE_ToRuby(mrb_state *state, int (*value)(sqlite3_file *, sqlite3_int64, int, void **)) {
    struct drb_foreign_object_ZTSPFiP12sqlite3_filexiPPvE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP12sqlite3_filexiPPvE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_59Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFiP12sqlite3_filexiPPvE);
    return mrb_obj_value(rdata);
}
struct drb_foreign_object_ZTSPFiP12sqlite3_filexPvE {
    drb_foreign_object_kind kind;
    int (*value)(sqlite3_file *, sqlite3_int64, void *);
    int should_free;
};
static mrb_data_type ForeignObjectType_ZTSPFiP12sqlite3_filexPvE = {"Function_60*", drb_free_foreign_object_indirect};
static int (*drb_ffi__ZTSPFiP12sqlite3_filexPvE_FromRuby(mrb_state *state, mrb_value self))(sqlite3_file *, sqlite3_int64, void *) {
    if (mrb_nil_p(self))
        return 0;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_60Pointer");
    drb_api->drb_typecheck_aggregate(state, self, klass, &ForeignObjectType_ZTSPFiP12sqlite3_filexPvE);
    return ((struct drb_foreign_object_ZTSPFiP12sqlite3_filexPvE *)DATA_PTR(self))->value;
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_filexPvE_ToRuby(mrb_state *state, int (*value)(sqlite3_file *, sqlite3_int64, void *)) {
    struct drb_foreign_object_ZTSPFiP12sqlite3_filexPvE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP12sqlite3_filexPvE));
    ptr->value = value;
    ptr->kind = drb_foreign_object_kind_pointer;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Function_60Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTSPFiP12sqlite3_filexPvE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPc_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPc *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPc));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(char));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "CharPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPc);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPc_GetValue(mrb_state *mrb, mrb_value value) {
    return drb_ffi__ZTSc_ToRuby(mrb, *drb_ffi__ZTSPc_FromRuby(mrb, value));
}
static mrb_value drb_ffi__ZTSPc_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPc_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPc_GetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    return drb_ffi__ZTSc_ToRuby(mrb, drb_ffi__ZTSPc_FromRuby(mrb, self)[index]);
}
static mrb_value drb_ffi__ZTSPc_SetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    char new_value = drb_ffi__ZTSc_FromRuby(mrb, args[1]);
    drb_ffi__ZTSPc_FromRuby(mrb, self)[index] = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPc_GetString(mrb_state *state, mrb_value self) {
    return drb_api->mrb_str_new_cstr(state, drb_ffi__ZTSPc_FromRuby(state, self));
}
static mrb_value drb_ffi__ZTSP7sqlite3_New(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot allocate pointer of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP7sqlite3_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access value of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP7sqlite3_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSP7sqlite3_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSP7sqlite3_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access value of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP7sqlite3_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change value of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiPviPPcS1_E_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFiPviPPcS1_E *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiPviPPcS1_E));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(int (void *, int, char **, char **)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_0Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFiPviPPcS1_E);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFiPviPPcS1_E_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiPviPPcS1_E_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFiPviPPcS1_E_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFiPviPPcS1_E_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiPviPPcS1_E_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPPc_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPPc *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPPc));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(char *));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "CharPointerPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPPc);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPPc_GetValue(mrb_state *mrb, mrb_value value) {
    return drb_ffi__ZTSPc_ToRuby(mrb, *drb_ffi__ZTSPPc_FromRuby(mrb, value));
}
static mrb_value drb_ffi__ZTSPPc_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPPc_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPPc_GetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    return drb_ffi__ZTSPc_ToRuby(mrb, drb_ffi__ZTSPPc_FromRuby(mrb, self)[index]);
}
static mrb_value drb_ffi__ZTSPPc_SetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    char *new_value = drb_ffi__ZTSPc_FromRuby(mrb, args[1]);
    drb_ffi__ZTSPPc_FromRuby(mrb, self)[index] = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiPviE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFiPviE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiPviE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(int (void *, int)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_1Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFiPviE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFiPviE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiPviE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFiPviE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFiPviE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiPviE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPPPc_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPPPc *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPPPc));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(char **));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "CharPointerPointerPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPPPc);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPPPc_GetValue(mrb_state *mrb, mrb_value value) {
    return drb_ffi__ZTSPPc_ToRuby(mrb, *drb_ffi__ZTSPPPc_FromRuby(mrb, value));
}
static mrb_value drb_ffi__ZTSPPPc_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPPPc_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPPPc_GetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    return drb_ffi__ZTSPPc_ToRuby(mrb, drb_ffi__ZTSPPPc_FromRuby(mrb, self)[index]);
}
static mrb_value drb_ffi__ZTSPPPc_SetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    char **new_value = drb_ffi__ZTSPPc_FromRuby(mrb, args[1]);
    drb_ffi__ZTSPPPc_FromRuby(mrb, self)[index] = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPi_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPi *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPi));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(int));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "IntPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPi);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPi_GetValue(mrb_state *mrb, mrb_value value) {
    return drb_ffi__ZTSi_ToRuby(mrb, *drb_ffi__ZTSPi_FromRuby(mrb, value));
}
static mrb_value drb_ffi__ZTSPi_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPi_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPi_GetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    return drb_ffi__ZTSi_ToRuby(mrb, drb_ffi__ZTSPi_FromRuby(mrb, self)[index]);
}
static mrb_value drb_ffi__ZTSPi_SetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    int new_value = drb_ffi__ZTSi_FromRuby(mrb, args[1]);
    drb_ffi__ZTSPi_FromRuby(mrb, self)[index] = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiPviPKcS1_S1_S1_E_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFiPviPKcS1_S1_S1_E *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiPviPKcS1_S1_S1_E));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(int (void *, int, const char *, const char *, const char *, const char *)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_2Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFiPviPKcS1_S1_S1_E);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFiPviPKcS1_S1_S1_E_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiPviPKcS1_S1_S1_E_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFiPviPKcS1_S1_S1_E_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFiPviPKcS1_S1_S1_E_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiPviPKcS1_S1_S1_E_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFvPvPKcE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFvPvPKcE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFvPvPKcE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(void (void *, const char *)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_3Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFvPvPKcE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFvPvPKcE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFvPvPKcE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFvPvPKcE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFvPvPKcE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFvPvPKcE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFvPvPKcyE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFvPvPKcyE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFvPvPKcyE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(void (void *, const char *, sqlite3_uint64)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_4Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFvPvPKcyE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFvPvPKcyE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFvPvPKcyE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFvPvPKcyE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFvPvPKcyE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFvPvPKcyE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFijPvS_S_E_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFijPvS_S_E *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFijPvS_S_E));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(int (unsigned int, void *, void *, void *)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_5Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFijPvS_S_E);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFijPvS_S_E_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFijPvS_S_E_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFijPvS_S_E_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFijPvS_S_E_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFijPvS_S_E_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiPvE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFiPvE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiPvE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(int (void *)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_6Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFiPvE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFiPvE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiPvE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFiPvE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFiPvE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiPvE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPP7sqlite3_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPP7sqlite3 *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPP7sqlite3));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(sqlite3 *));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Sqlite3PointerPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPP7sqlite3);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPP7sqlite3_GetValue(mrb_state *mrb, mrb_value value) {
    return drb_ffi__ZTSP7sqlite3_ToRuby(mrb, *drb_ffi__ZTSPP7sqlite3_FromRuby(mrb, value));
}
static mrb_value drb_ffi__ZTSPP7sqlite3_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPP7sqlite3_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPP7sqlite3_GetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    return drb_ffi__ZTSP7sqlite3_ToRuby(mrb, drb_ffi__ZTSPP7sqlite3_FromRuby(mrb, self)[index]);
}
static mrb_value drb_ffi__ZTSPP7sqlite3_SetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    sqlite3 *new_value = drb_ffi__ZTSP7sqlite3_FromRuby(mrb, args[1]);
    drb_ffi__ZTSPP7sqlite3_FromRuby(mrb, self)[index] = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP12sqlite3_file_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSP12sqlite3_file *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP12sqlite3_file));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(sqlite3_file));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Sqlite3_filePointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSP12sqlite3_file);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSP12sqlite3_file_GetValue(mrb_state *mrb, mrb_value value) {
    return drb_ffi__ZTS12sqlite3_file_ToRuby(mrb, *drb_ffi__ZTSP12sqlite3_file_FromRuby(mrb, value));
}
static mrb_value drb_ffi__ZTSP12sqlite3_file_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSP12sqlite3_file_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSP12sqlite3_file_GetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    return drb_ffi__ZTS12sqlite3_file_ToRuby(mrb, drb_ffi__ZTSP12sqlite3_file_FromRuby(mrb, self)[index]);
}
static mrb_value drb_ffi__ZTSP12sqlite3_file_SetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    sqlite3_file new_value = drb_ffi__ZTS12sqlite3_file_FromRuby(mrb, args[1]);
    drb_ffi__ZTSP12sqlite3_file_FromRuby(mrb, self)[index] = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPP12sqlite3_stmt_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPP12sqlite3_stmt *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPP12sqlite3_stmt));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(sqlite3_stmt *));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Sqlite3_stmtPointerPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPP12sqlite3_stmt);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPP12sqlite3_stmt_GetValue(mrb_state *mrb, mrb_value value) {
    return drb_ffi__ZTSP12sqlite3_stmt_ToRuby(mrb, *drb_ffi__ZTSPP12sqlite3_stmt_FromRuby(mrb, value));
}
static mrb_value drb_ffi__ZTSPP12sqlite3_stmt_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPP12sqlite3_stmt_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPP12sqlite3_stmt_GetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    return drb_ffi__ZTSP12sqlite3_stmt_ToRuby(mrb, drb_ffi__ZTSPP12sqlite3_stmt_FromRuby(mrb, self)[index]);
}
static mrb_value drb_ffi__ZTSPP12sqlite3_stmt_SetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    sqlite3_stmt *new_value = drb_ffi__ZTSP12sqlite3_stmt_FromRuby(mrb, args[1]);
    drb_ffi__ZTSPP12sqlite3_stmt_FromRuby(mrb, self)[index] = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPPv_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPPv *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPPv));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(void *));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "VoidPointerPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPPv);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPPv_GetValue(mrb_state *mrb, mrb_value value) {
    return drb_ffi__ZTSPv_ToRuby(mrb, *drb_ffi__ZTSPPv_FromRuby(mrb, value));
}
static mrb_value drb_ffi__ZTSPPv_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPPv_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPPv_GetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    return drb_ffi__ZTSPv_ToRuby(mrb, drb_ffi__ZTSPPv_FromRuby(mrb, self)[index]);
}
static mrb_value drb_ffi__ZTSPPv_SetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    void *new_value = drb_ffi__ZTSPv_FromRuby(mrb, args[1]);
    drb_ffi__ZTSPPv_FromRuby(mrb, self)[index] = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP12sqlite3_stmt_New(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot allocate pointer of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP12sqlite3_stmt_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access value of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP12sqlite3_stmt_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSP12sqlite3_stmt_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSP12sqlite3_stmt_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access value of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP12sqlite3_stmt_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change value of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFvPvE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFvPvE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFvPvE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(void (void *)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_7Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFvPvE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFvPvE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFvPvE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFvPvE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFvPvE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFvPvE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP13sqlite3_value_New(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot allocate pointer of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP13sqlite3_value_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access value of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP13sqlite3_value_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSP13sqlite3_value_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSP13sqlite3_value_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access value of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP13sqlite3_value_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change value of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPh_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPh *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPh));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(unsigned char));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Unsigned_charPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPh);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPh_GetValue(mrb_state *mrb, mrb_value value) {
    return drb_ffi__ZTSh_ToRuby(mrb, *drb_ffi__ZTSPh_FromRuby(mrb, value));
}
static mrb_value drb_ffi__ZTSPh_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPh_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPh_GetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    return drb_ffi__ZTSh_ToRuby(mrb, drb_ffi__ZTSPh_FromRuby(mrb, self)[index]);
}
static mrb_value drb_ffi__ZTSPh_SetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    unsigned char new_value = drb_ffi__ZTSh_FromRuby(mrb, args[1]);
    drb_ffi__ZTSPh_FromRuby(mrb, self)[index] = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPh_GetString(mrb_state *state, mrb_value self) {
    return drb_api->mrb_str_new_cstr(state, drb_ffi__ZTSPh_FromRuby(state, self));
}
static mrb_value drb_ffi__ZTSPFvP15sqlite3_contextiPP13sqlite3_valueE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFvP15sqlite3_contextiPP13sqlite3_valueE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFvP15sqlite3_contextiPP13sqlite3_valueE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(void (sqlite3_context *, int, sqlite3_value **)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_8Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFvP15sqlite3_contextiPP13sqlite3_valueE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFvP15sqlite3_contextiPP13sqlite3_valueE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFvP15sqlite3_contextiPP13sqlite3_valueE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFvP15sqlite3_contextiPP13sqlite3_valueE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFvP15sqlite3_contextiPP13sqlite3_valueE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFvP15sqlite3_contextiPP13sqlite3_valueE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFvP15sqlite3_contextE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFvP15sqlite3_contextE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFvP15sqlite3_contextE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(void (sqlite3_context *)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_9Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFvP15sqlite3_contextE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFvP15sqlite3_contextE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFvP15sqlite3_contextE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFvP15sqlite3_contextE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFvP15sqlite3_contextE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFvP15sqlite3_contextE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP15sqlite3_context_New(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot allocate pointer of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP15sqlite3_context_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access value of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP15sqlite3_context_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSP15sqlite3_context_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSP15sqlite3_context_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access value of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP15sqlite3_context_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change value of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFvPvxiE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFvPvxiE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFvPvxiE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(void (void *, sqlite3_int64, int)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_10Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFvPvxiE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFvPvxiE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFvPvxiE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFvPvxiE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFvPvxiE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFvPvxiE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiPviPKviS1_E_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFiPviPKviS1_E *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiPviPKviS1_E));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(int (void *, int, const void *, int, const void *)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_11Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFiPviPKviS1_E);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFiPviPKviS1_E_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiPviPKviS1_E_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFiPviPKviS1_E_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFiPviPKviS1_E_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiPviPKviS1_E_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFvPvP7sqlite3iPKcE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFvPvP7sqlite3iPKcE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFvPvP7sqlite3iPKcE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(void (void *, sqlite3 *, int, const char *)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_12Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFvPvP7sqlite3iPKcE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFvPvP7sqlite3iPKcE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFvPvP7sqlite3iPKcE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFvPvP7sqlite3iPKcE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFvPvP7sqlite3iPKcE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFvPvP7sqlite3iPKcE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFvPvP7sqlite3iPKvE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFvPvP7sqlite3iPKvE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFvPvP7sqlite3iPKvE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(void (void *, sqlite3 *, int, const void *)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_13Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFvPvP7sqlite3iPKvE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFvPvP7sqlite3iPKvE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFvPvP7sqlite3iPKvE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFvPvP7sqlite3iPKvE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFvPvP7sqlite3iPKvE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFvPvP7sqlite3iPKvE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFjPvPKcjjjE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFjPvPKcjjjE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFjPvPKcjjjE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(unsigned int (void *, const char *, unsigned int, unsigned int, unsigned int)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_14Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFjPvPKcjjjE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFjPvPKcjjjE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFjPvPKcjjjE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFjPvPKcjjjE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFjPvPKcjjjE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFjPvPKcjjjE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFvPviPKcS1_xE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFvPviPKcS1_xE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFvPviPKcS1_xE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(void (void *, int, const char *, const char *, sqlite3_int64)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_15Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFvPviPKcS1_xE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFvPviPKcS1_xE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFvPviPKcS1_xE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFvPviPKcS1_xE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFvPviPKcS1_xE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFvPviPKcS1_xE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFvvE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFvvE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFvvE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(void (void)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_16Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFvvE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFvvE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFvvE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFvvE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFvvE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFvvE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP14sqlite3_module_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSP14sqlite3_module *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP14sqlite3_module));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(sqlite3_module));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Sqlite3_modulePointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSP14sqlite3_module);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSP14sqlite3_module_GetValue(mrb_state *mrb, mrb_value value) {
    return drb_ffi__ZTS14sqlite3_module_ToRuby(mrb, *drb_ffi__ZTSP14sqlite3_module_FromRuby(mrb, value));
}
static mrb_value drb_ffi__ZTSP14sqlite3_module_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSP14sqlite3_module_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSP14sqlite3_module_GetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    return drb_ffi__ZTS14sqlite3_module_ToRuby(mrb, drb_ffi__ZTSP14sqlite3_module_FromRuby(mrb, self)[index]);
}
static mrb_value drb_ffi__ZTSP14sqlite3_module_SetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    sqlite3_module new_value = drb_ffi__ZTS14sqlite3_module_FromRuby(mrb, args[1]);
    drb_ffi__ZTSP14sqlite3_module_FromRuby(mrb, self)[index] = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPP12sqlite3_blob_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPP12sqlite3_blob *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPP12sqlite3_blob));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(sqlite3_blob *));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Sqlite3_blobPointerPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPP12sqlite3_blob);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPP12sqlite3_blob_GetValue(mrb_state *mrb, mrb_value value) {
    return drb_ffi__ZTSP12sqlite3_blob_ToRuby(mrb, *drb_ffi__ZTSPP12sqlite3_blob_FromRuby(mrb, value));
}
static mrb_value drb_ffi__ZTSPP12sqlite3_blob_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPP12sqlite3_blob_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPP12sqlite3_blob_GetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    return drb_ffi__ZTSP12sqlite3_blob_ToRuby(mrb, drb_ffi__ZTSPP12sqlite3_blob_FromRuby(mrb, self)[index]);
}
static mrb_value drb_ffi__ZTSPP12sqlite3_blob_SetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    sqlite3_blob *new_value = drb_ffi__ZTSP12sqlite3_blob_FromRuby(mrb, args[1]);
    drb_ffi__ZTSPP12sqlite3_blob_FromRuby(mrb, self)[index] = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP12sqlite3_blob_New(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot allocate pointer of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP12sqlite3_blob_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access value of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP12sqlite3_blob_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSP12sqlite3_blob_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSP12sqlite3_blob_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access value of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP12sqlite3_blob_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change value of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP11sqlite3_vfs_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSP11sqlite3_vfs *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP11sqlite3_vfs));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(sqlite3_vfs));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Sqlite3_vfsPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSP11sqlite3_vfs);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSP11sqlite3_vfs_GetValue(mrb_state *mrb, mrb_value value) {
    return drb_ffi__ZTS11sqlite3_vfs_ToRuby(mrb, *drb_ffi__ZTSP11sqlite3_vfs_FromRuby(mrb, value));
}
static mrb_value drb_ffi__ZTSP11sqlite3_vfs_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSP11sqlite3_vfs_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSP11sqlite3_vfs_GetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    return drb_ffi__ZTS11sqlite3_vfs_ToRuby(mrb, drb_ffi__ZTSP11sqlite3_vfs_FromRuby(mrb, self)[index]);
}
static mrb_value drb_ffi__ZTSP11sqlite3_vfs_SetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    sqlite3_vfs new_value = drb_ffi__ZTS11sqlite3_vfs_FromRuby(mrb, args[1]);
    drb_ffi__ZTSP11sqlite3_vfs_FromRuby(mrb, self)[index] = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP13sqlite3_mutex_New(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot allocate pointer of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP13sqlite3_mutex_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access value of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP13sqlite3_mutex_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSP13sqlite3_mutex_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSP13sqlite3_mutex_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access value of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP13sqlite3_mutex_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change value of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP11sqlite3_str_New(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot allocate pointer of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP11sqlite3_str_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access value of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP11sqlite3_str_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSP11sqlite3_str_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSP11sqlite3_str_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access value of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP11sqlite3_str_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change value of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPx_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPx *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPx));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(sqlite3_int64));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Long_longPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPx);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPx_GetValue(mrb_state *mrb, mrb_value value) {
    return drb_ffi__ZTSx_ToRuby(mrb, *drb_ffi__ZTSPx_FromRuby(mrb, value));
}
static mrb_value drb_ffi__ZTSPx_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPx_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPx_GetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    return drb_ffi__ZTSx_ToRuby(mrb, drb_ffi__ZTSPx_FromRuby(mrb, self)[index]);
}
static mrb_value drb_ffi__ZTSPx_SetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    sqlite3_int64 new_value = drb_ffi__ZTSx_FromRuby(mrb, args[1]);
    drb_ffi__ZTSPx_FromRuby(mrb, self)[index] = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP14sqlite3_backup_New(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot allocate pointer of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP14sqlite3_backup_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access value of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP14sqlite3_backup_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSP14sqlite3_backup_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSP14sqlite3_backup_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access value of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP14sqlite3_backup_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change value of incomplete type");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiPvP7sqlite3PKciE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFiPvP7sqlite3PKciE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiPvP7sqlite3PKciE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(int (void *, sqlite3 *, const char *, int)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_17Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFiPvP7sqlite3PKciE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFiPvP7sqlite3PKciE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiPvP7sqlite3PKciE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFiPvP7sqlite3PKciE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFiPvP7sqlite3PKciE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiPvP7sqlite3PKciE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP18sqlite3_index_info_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSP18sqlite3_index_info *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP18sqlite3_index_info));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(sqlite3_index_info));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Sqlite3_index_infoPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSP18sqlite3_index_info);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSP18sqlite3_index_info_GetValue(mrb_state *mrb, mrb_value value) {
    return drb_ffi__ZTS18sqlite3_index_info_ToRuby(mrb, *drb_ffi__ZTSP18sqlite3_index_info_FromRuby(mrb, value));
}
static mrb_value drb_ffi__ZTSP18sqlite3_index_info_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSP18sqlite3_index_info_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSP18sqlite3_index_info_GetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    return drb_ffi__ZTS18sqlite3_index_info_ToRuby(mrb, drb_ffi__ZTSP18sqlite3_index_info_FromRuby(mrb, self)[index]);
}
static mrb_value drb_ffi__ZTSP18sqlite3_index_info_SetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    sqlite3_index_info new_value = drb_ffi__ZTS18sqlite3_index_info_FromRuby(mrb, args[1]);
    drb_ffi__ZTSP18sqlite3_index_info_FromRuby(mrb, self)[index] = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPP13sqlite3_value_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPP13sqlite3_value *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPP13sqlite3_value));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(sqlite3_value *));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Sqlite3_valuePointerPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPP13sqlite3_value);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPP13sqlite3_value_GetValue(mrb_state *mrb, mrb_value value) {
    return drb_ffi__ZTSP13sqlite3_value_ToRuby(mrb, *drb_ffi__ZTSPP13sqlite3_value_FromRuby(mrb, value));
}
static mrb_value drb_ffi__ZTSPP13sqlite3_value_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPP13sqlite3_value_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPP13sqlite3_value_GetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    return drb_ffi__ZTSP13sqlite3_value_ToRuby(mrb, drb_ffi__ZTSPP13sqlite3_value_FromRuby(mrb, self)[index]);
}
static mrb_value drb_ffi__ZTSPP13sqlite3_value_SetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    sqlite3_value *new_value = drb_ffi__ZTSP13sqlite3_value_FromRuby(mrb, args[1]);
    drb_ffi__ZTSPP13sqlite3_value_FromRuby(mrb, self)[index] = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP22sqlite3_rtree_geometryiPdPiE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFiP22sqlite3_rtree_geometryiPdPiE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP22sqlite3_rtree_geometryiPdPiE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(int (sqlite3_rtree_geometry *, int, sqlite3_rtree_dbl *, int *)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_18Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFiP22sqlite3_rtree_geometryiPdPiE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFiP22sqlite3_rtree_geometryiPdPiE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP22sqlite3_rtree_geometryiPdPiE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFiP22sqlite3_rtree_geometryiPdPiE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFiP22sqlite3_rtree_geometryiPdPiE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP22sqlite3_rtree_geometryiPdPiE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP24sqlite3_rtree_query_infoE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFiP24sqlite3_rtree_query_infoE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP24sqlite3_rtree_query_infoE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(int (sqlite3_rtree_query_info *)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_19Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFiP24sqlite3_rtree_query_infoE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFiP24sqlite3_rtree_query_infoE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP24sqlite3_rtree_query_infoE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFiP24sqlite3_rtree_query_infoE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFiP24sqlite3_rtree_query_infoE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP24sqlite3_rtree_query_infoE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP18sqlite3_io_methods_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSP18sqlite3_io_methods *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP18sqlite3_io_methods));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(struct sqlite3_io_methods));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Sqlite3_io_methodsPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSP18sqlite3_io_methods);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSP18sqlite3_io_methods_GetValue(mrb_state *mrb, mrb_value value) {
    return drb_ffi__ZTS18sqlite3_io_methods_ToRuby(mrb, *drb_ffi__ZTSP18sqlite3_io_methods_FromRuby(mrb, value));
}
static mrb_value drb_ffi__ZTSP18sqlite3_io_methods_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSP18sqlite3_io_methods_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSP18sqlite3_io_methods_GetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    return drb_ffi__ZTS18sqlite3_io_methods_ToRuby(mrb, drb_ffi__ZTSP18sqlite3_io_methods_FromRuby(mrb, self)[index]);
}
static mrb_value drb_ffi__ZTSP18sqlite3_io_methods_SetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    struct sqlite3_io_methods new_value = drb_ffi__ZTS18sqlite3_io_methods_FromRuby(mrb, args[1]);
    drb_ffi__ZTSP18sqlite3_io_methods_FromRuby(mrb, self)[index] = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP7sqlite3PviPKPKcPP12sqlite3_vtabPPcE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFiP7sqlite3PviPKPKcPP12sqlite3_vtabPPcE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP7sqlite3PviPKPKcPP12sqlite3_vtabPPcE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(int (sqlite3 *, void *, int, const char *const *, sqlite3_vtab **, char **)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_20Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFiP7sqlite3PviPKPKcPP12sqlite3_vtabPPcE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFiP7sqlite3PviPKPKcPP12sqlite3_vtabPPcE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP7sqlite3PviPKPKcPP12sqlite3_vtabPPcE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFiP7sqlite3PviPKPKcPP12sqlite3_vtabPPcE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFiP7sqlite3PviPKPKcPP12sqlite3_vtabPPcE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP7sqlite3PviPKPKcPP12sqlite3_vtabPPcE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_vtabP18sqlite3_index_infoE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFiP12sqlite3_vtabP18sqlite3_index_infoE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP12sqlite3_vtabP18sqlite3_index_infoE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(int (sqlite3_vtab *, sqlite3_index_info *)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_21Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFiP12sqlite3_vtabP18sqlite3_index_infoE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_vtabP18sqlite3_index_infoE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_vtabP18sqlite3_index_infoE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFiP12sqlite3_vtabP18sqlite3_index_infoE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_vtabP18sqlite3_index_infoE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_vtabP18sqlite3_index_infoE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_vtabE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFiP12sqlite3_vtabE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP12sqlite3_vtabE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(int (sqlite3_vtab *)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_22Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFiP12sqlite3_vtabE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_vtabE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_vtabE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFiP12sqlite3_vtabE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_vtabE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_vtabE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_vtabPP19sqlite3_vtab_cursorE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFiP12sqlite3_vtabPP19sqlite3_vtab_cursorE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP12sqlite3_vtabPP19sqlite3_vtab_cursorE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(int (sqlite3_vtab *, sqlite3_vtab_cursor **)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_23Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFiP12sqlite3_vtabPP19sqlite3_vtab_cursorE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_vtabPP19sqlite3_vtab_cursorE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_vtabPP19sqlite3_vtab_cursorE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFiP12sqlite3_vtabPP19sqlite3_vtab_cursorE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_vtabPP19sqlite3_vtab_cursorE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_vtabPP19sqlite3_vtab_cursorE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP19sqlite3_vtab_cursorE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFiP19sqlite3_vtab_cursorE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP19sqlite3_vtab_cursorE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(int (sqlite3_vtab_cursor *)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_24Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFiP19sqlite3_vtab_cursorE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFiP19sqlite3_vtab_cursorE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP19sqlite3_vtab_cursorE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFiP19sqlite3_vtab_cursorE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFiP19sqlite3_vtab_cursorE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP19sqlite3_vtab_cursorE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP19sqlite3_vtab_cursoriPKciPP13sqlite3_valueE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFiP19sqlite3_vtab_cursoriPKciPP13sqlite3_valueE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP19sqlite3_vtab_cursoriPKciPP13sqlite3_valueE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(int (sqlite3_vtab_cursor *, int, const char *, int, sqlite3_value **)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_25Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFiP19sqlite3_vtab_cursoriPKciPP13sqlite3_valueE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFiP19sqlite3_vtab_cursoriPKciPP13sqlite3_valueE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP19sqlite3_vtab_cursoriPKciPP13sqlite3_valueE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFiP19sqlite3_vtab_cursoriPKciPP13sqlite3_valueE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFiP19sqlite3_vtab_cursoriPKciPP13sqlite3_valueE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP19sqlite3_vtab_cursoriPKciPP13sqlite3_valueE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP19sqlite3_vtab_cursorP15sqlite3_contextiE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFiP19sqlite3_vtab_cursorP15sqlite3_contextiE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP19sqlite3_vtab_cursorP15sqlite3_contextiE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(int (sqlite3_vtab_cursor *, sqlite3_context *, int)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_26Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFiP19sqlite3_vtab_cursorP15sqlite3_contextiE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFiP19sqlite3_vtab_cursorP15sqlite3_contextiE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP19sqlite3_vtab_cursorP15sqlite3_contextiE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFiP19sqlite3_vtab_cursorP15sqlite3_contextiE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFiP19sqlite3_vtab_cursorP15sqlite3_contextiE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP19sqlite3_vtab_cursorP15sqlite3_contextiE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP19sqlite3_vtab_cursorPxE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFiP19sqlite3_vtab_cursorPxE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP19sqlite3_vtab_cursorPxE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(int (sqlite3_vtab_cursor *, sqlite3_int64 *)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_27Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFiP19sqlite3_vtab_cursorPxE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFiP19sqlite3_vtab_cursorPxE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP19sqlite3_vtab_cursorPxE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFiP19sqlite3_vtab_cursorPxE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFiP19sqlite3_vtab_cursorPxE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP19sqlite3_vtab_cursorPxE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_vtabiPP13sqlite3_valuePxE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFiP12sqlite3_vtabiPP13sqlite3_valuePxE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP12sqlite3_vtabiPP13sqlite3_valuePxE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(int (sqlite3_vtab *, int, sqlite3_value **, sqlite3_int64 *)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_28Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFiP12sqlite3_vtabiPP13sqlite3_valuePxE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_vtabiPP13sqlite3_valuePxE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_vtabiPP13sqlite3_valuePxE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFiP12sqlite3_vtabiPP13sqlite3_valuePxE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_vtabiPP13sqlite3_valuePxE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_vtabiPP13sqlite3_valuePxE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_vtabiPKcPPFvP15sqlite3_contextiPP13sqlite3_valueEPPvE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFiP12sqlite3_vtabiPKcPPFvP15sqlite3_contextiPP13sqlite3_valueEPPvE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP12sqlite3_vtabiPKcPPFvP15sqlite3_contextiPP13sqlite3_valueEPPvE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(int (sqlite3_vtab *, int, const char *, void (**)(sqlite3_context *, int, sqlite3_value **), void **)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_29Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFiP12sqlite3_vtabiPKcPPFvP15sqlite3_contextiPP13sqlite3_valueEPPvE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_vtabiPKcPPFvP15sqlite3_contextiPP13sqlite3_valueEPPvE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_vtabiPKcPPFvP15sqlite3_contextiPP13sqlite3_valueEPPvE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFiP12sqlite3_vtabiPKcPPFvP15sqlite3_contextiPP13sqlite3_valueEPPvE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_vtabiPKcPPFvP15sqlite3_contextiPP13sqlite3_valueEPPvE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_vtabiPKcPPFvP15sqlite3_contextiPP13sqlite3_valueEPPvE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_vtabPKcE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFiP12sqlite3_vtabPKcE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP12sqlite3_vtabPKcE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(int (sqlite3_vtab *, const char *)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_30Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFiP12sqlite3_vtabPKcE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_vtabPKcE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_vtabPKcE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFiP12sqlite3_vtabPKcE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_vtabPKcE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_vtabPKcE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_vtabiE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFiP12sqlite3_vtabiE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP12sqlite3_vtabiE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(int (sqlite3_vtab *, int)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_31Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFiP12sqlite3_vtabiE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_vtabiE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_vtabiE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFiP12sqlite3_vtabiE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_vtabiE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_vtabiE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiPKcE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFiPKcE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiPKcE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(int (const char *)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_32Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFiPKcE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFiPKcE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiPKcE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFiPKcE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFiPKcE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiPKcE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP11sqlite3_vfsPKcP12sqlite3_fileiPiE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFiP11sqlite3_vfsPKcP12sqlite3_fileiPiE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP11sqlite3_vfsPKcP12sqlite3_fileiPiE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(int (sqlite3_vfs *, const char *, sqlite3_file *, int, int *)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_33Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFiP11sqlite3_vfsPKcP12sqlite3_fileiPiE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFiP11sqlite3_vfsPKcP12sqlite3_fileiPiE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP11sqlite3_vfsPKcP12sqlite3_fileiPiE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFiP11sqlite3_vfsPKcP12sqlite3_fileiPiE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFiP11sqlite3_vfsPKcP12sqlite3_fileiPiE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP11sqlite3_vfsPKcP12sqlite3_fileiPiE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP11sqlite3_vfsPKciE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFiP11sqlite3_vfsPKciE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP11sqlite3_vfsPKciE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(int (sqlite3_vfs *, const char *, int)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_34Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFiP11sqlite3_vfsPKciE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFiP11sqlite3_vfsPKciE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP11sqlite3_vfsPKciE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFiP11sqlite3_vfsPKciE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFiP11sqlite3_vfsPKciE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP11sqlite3_vfsPKciE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP11sqlite3_vfsPKciPiE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFiP11sqlite3_vfsPKciPiE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP11sqlite3_vfsPKciPiE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(int (sqlite3_vfs *, const char *, int, int *)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_35Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFiP11sqlite3_vfsPKciPiE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFiP11sqlite3_vfsPKciPiE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP11sqlite3_vfsPKciPiE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFiP11sqlite3_vfsPKciPiE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFiP11sqlite3_vfsPKciPiE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP11sqlite3_vfsPKciPiE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP11sqlite3_vfsPKciPcE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFiP11sqlite3_vfsPKciPcE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP11sqlite3_vfsPKciPcE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(int (sqlite3_vfs *, const char *, int, char *)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_36Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFiP11sqlite3_vfsPKciPcE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFiP11sqlite3_vfsPKciPcE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP11sqlite3_vfsPKciPcE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFiP11sqlite3_vfsPKciPcE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFiP11sqlite3_vfsPKciPcE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP11sqlite3_vfsPKciPcE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFPvP11sqlite3_vfsPKcE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFPvP11sqlite3_vfsPKcE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFPvP11sqlite3_vfsPKcE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(void *(sqlite3_vfs *, const char *)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_37Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFPvP11sqlite3_vfsPKcE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFPvP11sqlite3_vfsPKcE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFPvP11sqlite3_vfsPKcE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFPvP11sqlite3_vfsPKcE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFPvP11sqlite3_vfsPKcE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFPvP11sqlite3_vfsPKcE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFvP11sqlite3_vfsiPcE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFvP11sqlite3_vfsiPcE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFvP11sqlite3_vfsiPcE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(void (sqlite3_vfs *, int, char *)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_38Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFvP11sqlite3_vfsiPcE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFvP11sqlite3_vfsiPcE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFvP11sqlite3_vfsiPcE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFvP11sqlite3_vfsiPcE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFvP11sqlite3_vfsiPcE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFvP11sqlite3_vfsiPcE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFPFvvEP11sqlite3_vfsPvPKcE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFPFvvEP11sqlite3_vfsPvPKcE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFPFvvEP11sqlite3_vfsPvPKcE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(void (*(sqlite3_vfs *, void *, const char *))(void)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_39Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFPFvvEP11sqlite3_vfsPvPKcE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFPFvvEP11sqlite3_vfsPvPKcE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFPFvvEP11sqlite3_vfsPvPKcE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFPFvvEP11sqlite3_vfsPvPKcE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFPFvvEP11sqlite3_vfsPvPKcE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFPFvvEP11sqlite3_vfsPvPKcE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFvP11sqlite3_vfsPvE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFvP11sqlite3_vfsPvE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFvP11sqlite3_vfsPvE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(void (sqlite3_vfs *, void *)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_40Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFvP11sqlite3_vfsPvE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFvP11sqlite3_vfsPvE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFvP11sqlite3_vfsPvE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFvP11sqlite3_vfsPvE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFvP11sqlite3_vfsPvE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFvP11sqlite3_vfsPvE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP11sqlite3_vfsiPcE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFiP11sqlite3_vfsiPcE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP11sqlite3_vfsiPcE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(int (sqlite3_vfs *, int, char *)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_41Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFiP11sqlite3_vfsiPcE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFiP11sqlite3_vfsiPcE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP11sqlite3_vfsiPcE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFiP11sqlite3_vfsiPcE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFiP11sqlite3_vfsiPcE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP11sqlite3_vfsiPcE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP11sqlite3_vfsiE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFiP11sqlite3_vfsiE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP11sqlite3_vfsiE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(int (sqlite3_vfs *, int)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_42Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFiP11sqlite3_vfsiE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFiP11sqlite3_vfsiE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP11sqlite3_vfsiE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFiP11sqlite3_vfsiE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFiP11sqlite3_vfsiE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP11sqlite3_vfsiE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP11sqlite3_vfsPdE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFiP11sqlite3_vfsPdE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP11sqlite3_vfsPdE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(int (sqlite3_vfs *, double *)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_43Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFiP11sqlite3_vfsPdE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFiP11sqlite3_vfsPdE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP11sqlite3_vfsPdE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFiP11sqlite3_vfsPdE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFiP11sqlite3_vfsPdE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP11sqlite3_vfsPdE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP11sqlite3_vfsPxE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFiP11sqlite3_vfsPxE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP11sqlite3_vfsPxE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(int (sqlite3_vfs *, sqlite3_int64 *)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_44Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFiP11sqlite3_vfsPxE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFiP11sqlite3_vfsPxE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP11sqlite3_vfsPxE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFiP11sqlite3_vfsPxE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFiP11sqlite3_vfsPxE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP11sqlite3_vfsPxE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP11sqlite3_vfsPKcPFvvEE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFiP11sqlite3_vfsPKcPFvvEE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP11sqlite3_vfsPKcPFvvEE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(int (sqlite3_vfs *, const char *, sqlite3_syscall_ptr)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_45Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFiP11sqlite3_vfsPKcPFvvEE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFiP11sqlite3_vfsPKcPFvvEE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP11sqlite3_vfsPKcPFvvEE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFiP11sqlite3_vfsPKcPFvvEE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFiP11sqlite3_vfsPKcPFvvEE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP11sqlite3_vfsPKcPFvvEE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFPFvvEP11sqlite3_vfsPKcE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFPFvvEP11sqlite3_vfsPKcE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFPFvvEP11sqlite3_vfsPKcE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(sqlite3_syscall_ptr (sqlite3_vfs *, const char *)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_46Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFPFvvEP11sqlite3_vfsPKcE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFPFvvEP11sqlite3_vfsPKcE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFPFvvEP11sqlite3_vfsPKcE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFPFvvEP11sqlite3_vfsPKcE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFPFvvEP11sqlite3_vfsPKcE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFPFvvEP11sqlite3_vfsPKcE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFPKcP11sqlite3_vfsS0_E_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFPKcP11sqlite3_vfsS0_E *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFPKcP11sqlite3_vfsS0_E));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(const char *(sqlite3_vfs *, const char *)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_47Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFPKcP11sqlite3_vfsS0_E);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFPKcP11sqlite3_vfsS0_E_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFPKcP11sqlite3_vfsS0_E_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFPKcP11sqlite3_vfsS0_E_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFPKcP11sqlite3_vfsS0_E_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFPKcP11sqlite3_vfsS0_E_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP24sqlite3_index_constraint_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSP24sqlite3_index_constraint *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP24sqlite3_index_constraint));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(struct sqlite3_index_constraint));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Sqlite3_index_constraintPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSP24sqlite3_index_constraint);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSP24sqlite3_index_constraint_GetValue(mrb_state *mrb, mrb_value value) {
    return drb_ffi__ZTS24sqlite3_index_constraint_ToRuby(mrb, *drb_ffi__ZTSP24sqlite3_index_constraint_FromRuby(mrb, value));
}
static mrb_value drb_ffi__ZTSP24sqlite3_index_constraint_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSP24sqlite3_index_constraint_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSP24sqlite3_index_constraint_GetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    return drb_ffi__ZTS24sqlite3_index_constraint_ToRuby(mrb, drb_ffi__ZTSP24sqlite3_index_constraint_FromRuby(mrb, self)[index]);
}
static mrb_value drb_ffi__ZTSP24sqlite3_index_constraint_SetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    struct sqlite3_index_constraint new_value = drb_ffi__ZTS24sqlite3_index_constraint_FromRuby(mrb, args[1]);
    drb_ffi__ZTSP24sqlite3_index_constraint_FromRuby(mrb, self)[index] = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP21sqlite3_index_orderby_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSP21sqlite3_index_orderby *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP21sqlite3_index_orderby));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(struct sqlite3_index_orderby));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Sqlite3_index_orderbyPointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSP21sqlite3_index_orderby);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSP21sqlite3_index_orderby_GetValue(mrb_state *mrb, mrb_value value) {
    return drb_ffi__ZTS21sqlite3_index_orderby_ToRuby(mrb, *drb_ffi__ZTSP21sqlite3_index_orderby_FromRuby(mrb, value));
}
static mrb_value drb_ffi__ZTSP21sqlite3_index_orderby_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSP21sqlite3_index_orderby_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSP21sqlite3_index_orderby_GetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    return drb_ffi__ZTS21sqlite3_index_orderby_ToRuby(mrb, drb_ffi__ZTSP21sqlite3_index_orderby_FromRuby(mrb, self)[index]);
}
static mrb_value drb_ffi__ZTSP21sqlite3_index_orderby_SetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    struct sqlite3_index_orderby new_value = drb_ffi__ZTS21sqlite3_index_orderby_FromRuby(mrb, args[1]);
    drb_ffi__ZTSP21sqlite3_index_orderby_FromRuby(mrb, self)[index] = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSP30sqlite3_index_constraint_usage_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSP30sqlite3_index_constraint_usage *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSP30sqlite3_index_constraint_usage));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(struct sqlite3_index_constraint_usage));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Sqlite3_index_constraint_usagePointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSP30sqlite3_index_constraint_usage);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSP30sqlite3_index_constraint_usage_GetValue(mrb_state *mrb, mrb_value value) {
    return drb_ffi__ZTS30sqlite3_index_constraint_usage_ToRuby(mrb, *drb_ffi__ZTSP30sqlite3_index_constraint_usage_FromRuby(mrb, value));
}
static mrb_value drb_ffi__ZTSP30sqlite3_index_constraint_usage_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSP30sqlite3_index_constraint_usage_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSP30sqlite3_index_constraint_usage_GetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    return drb_ffi__ZTS30sqlite3_index_constraint_usage_ToRuby(mrb, drb_ffi__ZTSP30sqlite3_index_constraint_usage_FromRuby(mrb, self)[index]);
}
static mrb_value drb_ffi__ZTSP30sqlite3_index_constraint_usage_SetAt(mrb_state *mrb, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(mrb, "*", &args, &argc);
    int index = drb_ffi__ZTSi_FromRuby(mrb, args[0]);
    struct sqlite3_index_constraint_usage new_value = drb_ffi__ZTS30sqlite3_index_constraint_usage_FromRuby(mrb, args[1]);
    drb_ffi__ZTSP30sqlite3_index_constraint_usage_FromRuby(mrb, self)[index] = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_fileE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFiP12sqlite3_fileE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP12sqlite3_fileE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(int (sqlite3_file *)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_48Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFiP12sqlite3_fileE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_fileE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_fileE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFiP12sqlite3_fileE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_fileE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_fileE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_filePvixE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFiP12sqlite3_filePvixE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP12sqlite3_filePvixE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(int (sqlite3_file *, void *, int, sqlite3_int64)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_49Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFiP12sqlite3_filePvixE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_filePvixE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_filePvixE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFiP12sqlite3_filePvixE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_filePvixE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_filePvixE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_filePKvixE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFiP12sqlite3_filePKvixE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP12sqlite3_filePKvixE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(int (sqlite3_file *, const void *, int, sqlite3_int64)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_50Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFiP12sqlite3_filePKvixE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_filePKvixE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_filePKvixE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFiP12sqlite3_filePKvixE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_filePKvixE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_filePKvixE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_filexE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFiP12sqlite3_filexE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP12sqlite3_filexE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(int (sqlite3_file *, sqlite3_int64)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_51Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFiP12sqlite3_filexE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_filexE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_filexE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFiP12sqlite3_filexE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_filexE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_filexE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_fileiE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFiP12sqlite3_fileiE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP12sqlite3_fileiE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(int (sqlite3_file *, int)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_52Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFiP12sqlite3_fileiE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_fileiE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_fileiE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFiP12sqlite3_fileiE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_fileiE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_fileiE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_filePxE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFiP12sqlite3_filePxE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP12sqlite3_filePxE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(int (sqlite3_file *, sqlite3_int64 *)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_53Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFiP12sqlite3_filePxE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_filePxE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_filePxE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFiP12sqlite3_filePxE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_filePxE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_filePxE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_filePiE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFiP12sqlite3_filePiE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP12sqlite3_filePiE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(int (sqlite3_file *, int *)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_54Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFiP12sqlite3_filePiE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_filePiE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_filePiE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFiP12sqlite3_filePiE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_filePiE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_filePiE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_fileiPvE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFiP12sqlite3_fileiPvE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP12sqlite3_fileiPvE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(int (sqlite3_file *, int, void *)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_55Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFiP12sqlite3_fileiPvE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_fileiPvE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_fileiPvE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFiP12sqlite3_fileiPvE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_fileiPvE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_fileiPvE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_fileiiiPPVvE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFiP12sqlite3_fileiiiPPVvE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP12sqlite3_fileiiiPPVvE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(int (sqlite3_file *, int, int, int, volatile void **)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_56Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFiP12sqlite3_fileiiiPPVvE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_fileiiiPPVvE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_fileiiiPPVvE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFiP12sqlite3_fileiiiPPVvE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_fileiiiPPVvE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_fileiiiPPVvE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_fileiiiE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFiP12sqlite3_fileiiiE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP12sqlite3_fileiiiE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(int (sqlite3_file *, int, int, int)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_57Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFiP12sqlite3_fileiiiE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_fileiiiE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_fileiiiE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFiP12sqlite3_fileiiiE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_fileiiiE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_fileiiiE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFvP12sqlite3_fileE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFvP12sqlite3_fileE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFvP12sqlite3_fileE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(void (sqlite3_file *)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_58Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFvP12sqlite3_fileE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFvP12sqlite3_fileE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFvP12sqlite3_fileE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFvP12sqlite3_fileE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFvP12sqlite3_fileE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFvP12sqlite3_fileE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_filexiPPvE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFiP12sqlite3_filexiPPvE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP12sqlite3_filexiPPvE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(int (sqlite3_file *, sqlite3_int64, int, void **)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_59Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFiP12sqlite3_filexiPPvE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_filexiPPvE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_filexiPPvE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFiP12sqlite3_filexiPPvE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_filexiPPvE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_filexiPPvE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_filexPvE_New(mrb_state *mrb, mrb_value self) {
    struct drb_foreign_object_ZTSPFiP12sqlite3_filexPvE *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTSPFiP12sqlite3_filexPvE));
    ptr->kind = drb_foreign_object_kind_pointer;
    ptr->value = calloc(1, sizeof(int (sqlite3_file *, sqlite3_int64, void *)));
    ptr->should_free = 1;
    struct RClass *FFI = drb_api->mrb_module_get(mrb, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(mrb, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(mrb, module, "Function_60Pointer");
    struct RData *rdata = drb_api->mrb_data_object_alloc(mrb, klass, ptr, &ForeignObjectType_ZTSPFiP12sqlite3_filexPvE);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_filexPvE_GetValue(mrb_state *mrb, mrb_value value) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_filexPvE_IsNil(mrb_state *state, mrb_value self) {
    if (drb_ffi__ZTSPFiP12sqlite3_filexPvE_FromRuby(state, self) == 0)
        return mrb_true_value();
    else
        return mrb_false_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_filexPvE_GetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot access underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTSPFiP12sqlite3_filexPvE_SetAt(mrb_state *mrb, mrb_value self) {
    drb_api->mrb_raise(mrb, drb_api->drb_getruntime_error(mrb), "Cannot change underlying value of the function pointer");
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS12sqlite3_file_New(mrb_state *state, mrb_value self) {
    struct drb_foreign_object_ZTS12sqlite3_file *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS12sqlite3_file *));
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3_file");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTS12sqlite3_file);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTS12sqlite3_file_pMethods_Get(mrb_state *state, mrb_value self) {
    sqlite3_file record = drb_ffi__ZTS12sqlite3_file_FromRuby(state, self);
    return drb_ffi__ZTSP18sqlite3_io_methods_ToRuby(state, record.pMethods);
}
static mrb_value drb_ffi__ZTS12sqlite3_file_pMethods_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    struct sqlite3_io_methods *new_value = drb_ffi__ZTSP18sqlite3_io_methods_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS12sqlite3_file *)DATA_PTR(self))->value)->pMethods = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS14sqlite3_module_New(mrb_state *state, mrb_value self) {
    struct drb_foreign_object_ZTS14sqlite3_module *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS14sqlite3_module *));
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3_module");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTS14sqlite3_module);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTS14sqlite3_module_iVersion_Get(mrb_state *state, mrb_value self) {
    sqlite3_module record = drb_ffi__ZTS14sqlite3_module_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.iVersion);
}
static mrb_value drb_ffi__ZTS14sqlite3_module_iVersion_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS14sqlite3_module *)DATA_PTR(self))->value)->iVersion = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS14sqlite3_module_xCreate_Get(mrb_state *state, mrb_value self) {
    sqlite3_module record = drb_ffi__ZTS14sqlite3_module_FromRuby(state, self);
    return drb_ffi__ZTSPFiP7sqlite3PviPKPKcPP12sqlite3_vtabPPcE_ToRuby(state, record.xCreate);
}
static mrb_value drb_ffi__ZTS14sqlite3_module_xCreate_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int (*new_value)(sqlite3 *, void *, int, const char *const *, sqlite3_vtab **, char **) = drb_ffi__ZTSPFiP7sqlite3PviPKPKcPP12sqlite3_vtabPPcE_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS14sqlite3_module *)DATA_PTR(self))->value)->xCreate = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS14sqlite3_module_xConnect_Get(mrb_state *state, mrb_value self) {
    sqlite3_module record = drb_ffi__ZTS14sqlite3_module_FromRuby(state, self);
    return drb_ffi__ZTSPFiP7sqlite3PviPKPKcPP12sqlite3_vtabPPcE_ToRuby(state, record.xConnect);
}
static mrb_value drb_ffi__ZTS14sqlite3_module_xConnect_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int (*new_value)(sqlite3 *, void *, int, const char *const *, sqlite3_vtab **, char **) = drb_ffi__ZTSPFiP7sqlite3PviPKPKcPP12sqlite3_vtabPPcE_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS14sqlite3_module *)DATA_PTR(self))->value)->xConnect = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS14sqlite3_module_xBestIndex_Get(mrb_state *state, mrb_value self) {
    sqlite3_module record = drb_ffi__ZTS14sqlite3_module_FromRuby(state, self);
    return drb_ffi__ZTSPFiP12sqlite3_vtabP18sqlite3_index_infoE_ToRuby(state, record.xBestIndex);
}
static mrb_value drb_ffi__ZTS14sqlite3_module_xBestIndex_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int (*new_value)(sqlite3_vtab *, sqlite3_index_info *) = drb_ffi__ZTSPFiP12sqlite3_vtabP18sqlite3_index_infoE_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS14sqlite3_module *)DATA_PTR(self))->value)->xBestIndex = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS14sqlite3_module_xDisconnect_Get(mrb_state *state, mrb_value self) {
    sqlite3_module record = drb_ffi__ZTS14sqlite3_module_FromRuby(state, self);
    return drb_ffi__ZTSPFiP12sqlite3_vtabE_ToRuby(state, record.xDisconnect);
}
static mrb_value drb_ffi__ZTS14sqlite3_module_xDisconnect_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int (*new_value)(sqlite3_vtab *) = drb_ffi__ZTSPFiP12sqlite3_vtabE_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS14sqlite3_module *)DATA_PTR(self))->value)->xDisconnect = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS14sqlite3_module_xDestroy_Get(mrb_state *state, mrb_value self) {
    sqlite3_module record = drb_ffi__ZTS14sqlite3_module_FromRuby(state, self);
    return drb_ffi__ZTSPFiP12sqlite3_vtabE_ToRuby(state, record.xDestroy);
}
static mrb_value drb_ffi__ZTS14sqlite3_module_xDestroy_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int (*new_value)(sqlite3_vtab *) = drb_ffi__ZTSPFiP12sqlite3_vtabE_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS14sqlite3_module *)DATA_PTR(self))->value)->xDestroy = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS14sqlite3_module_xOpen_Get(mrb_state *state, mrb_value self) {
    sqlite3_module record = drb_ffi__ZTS14sqlite3_module_FromRuby(state, self);
    return drb_ffi__ZTSPFiP12sqlite3_vtabPP19sqlite3_vtab_cursorE_ToRuby(state, record.xOpen);
}
static mrb_value drb_ffi__ZTS14sqlite3_module_xOpen_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int (*new_value)(sqlite3_vtab *, sqlite3_vtab_cursor **) = drb_ffi__ZTSPFiP12sqlite3_vtabPP19sqlite3_vtab_cursorE_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS14sqlite3_module *)DATA_PTR(self))->value)->xOpen = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS14sqlite3_module_xClose_Get(mrb_state *state, mrb_value self) {
    sqlite3_module record = drb_ffi__ZTS14sqlite3_module_FromRuby(state, self);
    return drb_ffi__ZTSPFiP19sqlite3_vtab_cursorE_ToRuby(state, record.xClose);
}
static mrb_value drb_ffi__ZTS14sqlite3_module_xClose_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int (*new_value)(sqlite3_vtab_cursor *) = drb_ffi__ZTSPFiP19sqlite3_vtab_cursorE_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS14sqlite3_module *)DATA_PTR(self))->value)->xClose = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS14sqlite3_module_xFilter_Get(mrb_state *state, mrb_value self) {
    sqlite3_module record = drb_ffi__ZTS14sqlite3_module_FromRuby(state, self);
    return drb_ffi__ZTSPFiP19sqlite3_vtab_cursoriPKciPP13sqlite3_valueE_ToRuby(state, record.xFilter);
}
static mrb_value drb_ffi__ZTS14sqlite3_module_xFilter_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int (*new_value)(sqlite3_vtab_cursor *, int, const char *, int, sqlite3_value **) = drb_ffi__ZTSPFiP19sqlite3_vtab_cursoriPKciPP13sqlite3_valueE_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS14sqlite3_module *)DATA_PTR(self))->value)->xFilter = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS14sqlite3_module_xNext_Get(mrb_state *state, mrb_value self) {
    sqlite3_module record = drb_ffi__ZTS14sqlite3_module_FromRuby(state, self);
    return drb_ffi__ZTSPFiP19sqlite3_vtab_cursorE_ToRuby(state, record.xNext);
}
static mrb_value drb_ffi__ZTS14sqlite3_module_xNext_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int (*new_value)(sqlite3_vtab_cursor *) = drb_ffi__ZTSPFiP19sqlite3_vtab_cursorE_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS14sqlite3_module *)DATA_PTR(self))->value)->xNext = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS14sqlite3_module_xEof_Get(mrb_state *state, mrb_value self) {
    sqlite3_module record = drb_ffi__ZTS14sqlite3_module_FromRuby(state, self);
    return drb_ffi__ZTSPFiP19sqlite3_vtab_cursorE_ToRuby(state, record.xEof);
}
static mrb_value drb_ffi__ZTS14sqlite3_module_xEof_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int (*new_value)(sqlite3_vtab_cursor *) = drb_ffi__ZTSPFiP19sqlite3_vtab_cursorE_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS14sqlite3_module *)DATA_PTR(self))->value)->xEof = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS14sqlite3_module_xColumn_Get(mrb_state *state, mrb_value self) {
    sqlite3_module record = drb_ffi__ZTS14sqlite3_module_FromRuby(state, self);
    return drb_ffi__ZTSPFiP19sqlite3_vtab_cursorP15sqlite3_contextiE_ToRuby(state, record.xColumn);
}
static mrb_value drb_ffi__ZTS14sqlite3_module_xColumn_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int (*new_value)(sqlite3_vtab_cursor *, sqlite3_context *, int) = drb_ffi__ZTSPFiP19sqlite3_vtab_cursorP15sqlite3_contextiE_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS14sqlite3_module *)DATA_PTR(self))->value)->xColumn = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS14sqlite3_module_xRowid_Get(mrb_state *state, mrb_value self) {
    sqlite3_module record = drb_ffi__ZTS14sqlite3_module_FromRuby(state, self);
    return drb_ffi__ZTSPFiP19sqlite3_vtab_cursorPxE_ToRuby(state, record.xRowid);
}
static mrb_value drb_ffi__ZTS14sqlite3_module_xRowid_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int (*new_value)(sqlite3_vtab_cursor *, sqlite3_int64 *) = drb_ffi__ZTSPFiP19sqlite3_vtab_cursorPxE_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS14sqlite3_module *)DATA_PTR(self))->value)->xRowid = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS14sqlite3_module_xUpdate_Get(mrb_state *state, mrb_value self) {
    sqlite3_module record = drb_ffi__ZTS14sqlite3_module_FromRuby(state, self);
    return drb_ffi__ZTSPFiP12sqlite3_vtabiPP13sqlite3_valuePxE_ToRuby(state, record.xUpdate);
}
static mrb_value drb_ffi__ZTS14sqlite3_module_xUpdate_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int (*new_value)(sqlite3_vtab *, int, sqlite3_value **, sqlite3_int64 *) = drb_ffi__ZTSPFiP12sqlite3_vtabiPP13sqlite3_valuePxE_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS14sqlite3_module *)DATA_PTR(self))->value)->xUpdate = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS14sqlite3_module_xBegin_Get(mrb_state *state, mrb_value self) {
    sqlite3_module record = drb_ffi__ZTS14sqlite3_module_FromRuby(state, self);
    return drb_ffi__ZTSPFiP12sqlite3_vtabE_ToRuby(state, record.xBegin);
}
static mrb_value drb_ffi__ZTS14sqlite3_module_xBegin_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int (*new_value)(sqlite3_vtab *) = drb_ffi__ZTSPFiP12sqlite3_vtabE_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS14sqlite3_module *)DATA_PTR(self))->value)->xBegin = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS14sqlite3_module_xSync_Get(mrb_state *state, mrb_value self) {
    sqlite3_module record = drb_ffi__ZTS14sqlite3_module_FromRuby(state, self);
    return drb_ffi__ZTSPFiP12sqlite3_vtabE_ToRuby(state, record.xSync);
}
static mrb_value drb_ffi__ZTS14sqlite3_module_xSync_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int (*new_value)(sqlite3_vtab *) = drb_ffi__ZTSPFiP12sqlite3_vtabE_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS14sqlite3_module *)DATA_PTR(self))->value)->xSync = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS14sqlite3_module_xCommit_Get(mrb_state *state, mrb_value self) {
    sqlite3_module record = drb_ffi__ZTS14sqlite3_module_FromRuby(state, self);
    return drb_ffi__ZTSPFiP12sqlite3_vtabE_ToRuby(state, record.xCommit);
}
static mrb_value drb_ffi__ZTS14sqlite3_module_xCommit_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int (*new_value)(sqlite3_vtab *) = drb_ffi__ZTSPFiP12sqlite3_vtabE_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS14sqlite3_module *)DATA_PTR(self))->value)->xCommit = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS14sqlite3_module_xRollback_Get(mrb_state *state, mrb_value self) {
    sqlite3_module record = drb_ffi__ZTS14sqlite3_module_FromRuby(state, self);
    return drb_ffi__ZTSPFiP12sqlite3_vtabE_ToRuby(state, record.xRollback);
}
static mrb_value drb_ffi__ZTS14sqlite3_module_xRollback_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int (*new_value)(sqlite3_vtab *) = drb_ffi__ZTSPFiP12sqlite3_vtabE_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS14sqlite3_module *)DATA_PTR(self))->value)->xRollback = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS14sqlite3_module_xFindFunction_Get(mrb_state *state, mrb_value self) {
    sqlite3_module record = drb_ffi__ZTS14sqlite3_module_FromRuby(state, self);
    return drb_ffi__ZTSPFiP12sqlite3_vtabiPKcPPFvP15sqlite3_contextiPP13sqlite3_valueEPPvE_ToRuby(state, record.xFindFunction);
}
static mrb_value drb_ffi__ZTS14sqlite3_module_xFindFunction_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int (*new_value)(sqlite3_vtab *, int, const char *, void (**)(sqlite3_context *, int, sqlite3_value **), void **) = drb_ffi__ZTSPFiP12sqlite3_vtabiPKcPPFvP15sqlite3_contextiPP13sqlite3_valueEPPvE_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS14sqlite3_module *)DATA_PTR(self))->value)->xFindFunction = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS14sqlite3_module_xRename_Get(mrb_state *state, mrb_value self) {
    sqlite3_module record = drb_ffi__ZTS14sqlite3_module_FromRuby(state, self);
    return drb_ffi__ZTSPFiP12sqlite3_vtabPKcE_ToRuby(state, record.xRename);
}
static mrb_value drb_ffi__ZTS14sqlite3_module_xRename_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int (*new_value)(sqlite3_vtab *, const char *) = drb_ffi__ZTSPFiP12sqlite3_vtabPKcE_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS14sqlite3_module *)DATA_PTR(self))->value)->xRename = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS14sqlite3_module_xSavepoint_Get(mrb_state *state, mrb_value self) {
    sqlite3_module record = drb_ffi__ZTS14sqlite3_module_FromRuby(state, self);
    return drb_ffi__ZTSPFiP12sqlite3_vtabiE_ToRuby(state, record.xSavepoint);
}
static mrb_value drb_ffi__ZTS14sqlite3_module_xSavepoint_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int (*new_value)(sqlite3_vtab *, int) = drb_ffi__ZTSPFiP12sqlite3_vtabiE_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS14sqlite3_module *)DATA_PTR(self))->value)->xSavepoint = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS14sqlite3_module_xRelease_Get(mrb_state *state, mrb_value self) {
    sqlite3_module record = drb_ffi__ZTS14sqlite3_module_FromRuby(state, self);
    return drb_ffi__ZTSPFiP12sqlite3_vtabiE_ToRuby(state, record.xRelease);
}
static mrb_value drb_ffi__ZTS14sqlite3_module_xRelease_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int (*new_value)(sqlite3_vtab *, int) = drb_ffi__ZTSPFiP12sqlite3_vtabiE_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS14sqlite3_module *)DATA_PTR(self))->value)->xRelease = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS14sqlite3_module_xRollbackTo_Get(mrb_state *state, mrb_value self) {
    sqlite3_module record = drb_ffi__ZTS14sqlite3_module_FromRuby(state, self);
    return drb_ffi__ZTSPFiP12sqlite3_vtabiE_ToRuby(state, record.xRollbackTo);
}
static mrb_value drb_ffi__ZTS14sqlite3_module_xRollbackTo_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int (*new_value)(sqlite3_vtab *, int) = drb_ffi__ZTSPFiP12sqlite3_vtabiE_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS14sqlite3_module *)DATA_PTR(self))->value)->xRollbackTo = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS14sqlite3_module_xShadowName_Get(mrb_state *state, mrb_value self) {
    sqlite3_module record = drb_ffi__ZTS14sqlite3_module_FromRuby(state, self);
    return drb_ffi__ZTSPFiPKcE_ToRuby(state, record.xShadowName);
}
static mrb_value drb_ffi__ZTS14sqlite3_module_xShadowName_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int (*new_value)(const char *) = drb_ffi__ZTSPFiPKcE_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS14sqlite3_module *)DATA_PTR(self))->value)->xShadowName = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS11sqlite3_vfs_New(mrb_state *state, mrb_value self) {
    struct drb_foreign_object_ZTS11sqlite3_vfs *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS11sqlite3_vfs *));
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3_vfs");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTS11sqlite3_vfs);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTS11sqlite3_vfs_iVersion_Get(mrb_state *state, mrb_value self) {
    sqlite3_vfs record = drb_ffi__ZTS11sqlite3_vfs_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.iVersion);
}
static mrb_value drb_ffi__ZTS11sqlite3_vfs_iVersion_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS11sqlite3_vfs *)DATA_PTR(self))->value)->iVersion = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS11sqlite3_vfs_szOsFile_Get(mrb_state *state, mrb_value self) {
    sqlite3_vfs record = drb_ffi__ZTS11sqlite3_vfs_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.szOsFile);
}
static mrb_value drb_ffi__ZTS11sqlite3_vfs_szOsFile_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS11sqlite3_vfs *)DATA_PTR(self))->value)->szOsFile = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS11sqlite3_vfs_mxPathname_Get(mrb_state *state, mrb_value self) {
    sqlite3_vfs record = drb_ffi__ZTS11sqlite3_vfs_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.mxPathname);
}
static mrb_value drb_ffi__ZTS11sqlite3_vfs_mxPathname_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS11sqlite3_vfs *)DATA_PTR(self))->value)->mxPathname = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS11sqlite3_vfs_pNext_Get(mrb_state *state, mrb_value self) {
    sqlite3_vfs record = drb_ffi__ZTS11sqlite3_vfs_FromRuby(state, self);
    return drb_ffi__ZTSP11sqlite3_vfs_ToRuby(state, record.pNext);
}
static mrb_value drb_ffi__ZTS11sqlite3_vfs_pNext_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    sqlite3_vfs *new_value = drb_ffi__ZTSP11sqlite3_vfs_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS11sqlite3_vfs *)DATA_PTR(self))->value)->pNext = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS11sqlite3_vfs_zName_Get(mrb_state *state, mrb_value self) {
    sqlite3_vfs record = drb_ffi__ZTS11sqlite3_vfs_FromRuby(state, self);
    return drb_ffi__ZTSPc_ToRuby(state, record.zName);
}
static mrb_value drb_ffi__ZTS11sqlite3_vfs_zName_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    char *new_value = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS11sqlite3_vfs *)DATA_PTR(self))->value)->zName = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS11sqlite3_vfs_pAppData_Get(mrb_state *state, mrb_value self) {
    sqlite3_vfs record = drb_ffi__ZTS11sqlite3_vfs_FromRuby(state, self);
    return drb_ffi__ZTSPv_ToRuby(state, record.pAppData);
}
static mrb_value drb_ffi__ZTS11sqlite3_vfs_pAppData_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    void *new_value = drb_ffi__ZTSPv_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS11sqlite3_vfs *)DATA_PTR(self))->value)->pAppData = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS11sqlite3_vfs_xOpen_Get(mrb_state *state, mrb_value self) {
    sqlite3_vfs record = drb_ffi__ZTS11sqlite3_vfs_FromRuby(state, self);
    return drb_ffi__ZTSPFiP11sqlite3_vfsPKcP12sqlite3_fileiPiE_ToRuby(state, record.xOpen);
}
static mrb_value drb_ffi__ZTS11sqlite3_vfs_xOpen_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int (*new_value)(sqlite3_vfs *, const char *, sqlite3_file *, int, int *) = drb_ffi__ZTSPFiP11sqlite3_vfsPKcP12sqlite3_fileiPiE_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS11sqlite3_vfs *)DATA_PTR(self))->value)->xOpen = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS11sqlite3_vfs_xDelete_Get(mrb_state *state, mrb_value self) {
    sqlite3_vfs record = drb_ffi__ZTS11sqlite3_vfs_FromRuby(state, self);
    return drb_ffi__ZTSPFiP11sqlite3_vfsPKciE_ToRuby(state, record.xDelete);
}
static mrb_value drb_ffi__ZTS11sqlite3_vfs_xDelete_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int (*new_value)(sqlite3_vfs *, const char *, int) = drb_ffi__ZTSPFiP11sqlite3_vfsPKciE_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS11sqlite3_vfs *)DATA_PTR(self))->value)->xDelete = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS11sqlite3_vfs_xAccess_Get(mrb_state *state, mrb_value self) {
    sqlite3_vfs record = drb_ffi__ZTS11sqlite3_vfs_FromRuby(state, self);
    return drb_ffi__ZTSPFiP11sqlite3_vfsPKciPiE_ToRuby(state, record.xAccess);
}
static mrb_value drb_ffi__ZTS11sqlite3_vfs_xAccess_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int (*new_value)(sqlite3_vfs *, const char *, int, int *) = drb_ffi__ZTSPFiP11sqlite3_vfsPKciPiE_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS11sqlite3_vfs *)DATA_PTR(self))->value)->xAccess = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS11sqlite3_vfs_xFullPathname_Get(mrb_state *state, mrb_value self) {
    sqlite3_vfs record = drb_ffi__ZTS11sqlite3_vfs_FromRuby(state, self);
    return drb_ffi__ZTSPFiP11sqlite3_vfsPKciPcE_ToRuby(state, record.xFullPathname);
}
static mrb_value drb_ffi__ZTS11sqlite3_vfs_xFullPathname_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int (*new_value)(sqlite3_vfs *, const char *, int, char *) = drb_ffi__ZTSPFiP11sqlite3_vfsPKciPcE_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS11sqlite3_vfs *)DATA_PTR(self))->value)->xFullPathname = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS11sqlite3_vfs_xDlOpen_Get(mrb_state *state, mrb_value self) {
    sqlite3_vfs record = drb_ffi__ZTS11sqlite3_vfs_FromRuby(state, self);
    return drb_ffi__ZTSPFPvP11sqlite3_vfsPKcE_ToRuby(state, record.xDlOpen);
}
static mrb_value drb_ffi__ZTS11sqlite3_vfs_xDlOpen_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    void *(*new_value)(sqlite3_vfs *, const char *) = drb_ffi__ZTSPFPvP11sqlite3_vfsPKcE_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS11sqlite3_vfs *)DATA_PTR(self))->value)->xDlOpen = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS11sqlite3_vfs_xDlError_Get(mrb_state *state, mrb_value self) {
    sqlite3_vfs record = drb_ffi__ZTS11sqlite3_vfs_FromRuby(state, self);
    return drb_ffi__ZTSPFvP11sqlite3_vfsiPcE_ToRuby(state, record.xDlError);
}
static mrb_value drb_ffi__ZTS11sqlite3_vfs_xDlError_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    void (*new_value)(sqlite3_vfs *, int, char *) = drb_ffi__ZTSPFvP11sqlite3_vfsiPcE_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS11sqlite3_vfs *)DATA_PTR(self))->value)->xDlError = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS11sqlite3_vfs_xDlSym_Get(mrb_state *state, mrb_value self) {
    sqlite3_vfs record = drb_ffi__ZTS11sqlite3_vfs_FromRuby(state, self);
    return drb_ffi__ZTSPFPFvvEP11sqlite3_vfsPvPKcE_ToRuby(state, record.xDlSym);
}
static mrb_value drb_ffi__ZTS11sqlite3_vfs_xDlSym_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    void (*(*new_value)(sqlite3_vfs *, void *, const char *))(void) = drb_ffi__ZTSPFPFvvEP11sqlite3_vfsPvPKcE_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS11sqlite3_vfs *)DATA_PTR(self))->value)->xDlSym = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS11sqlite3_vfs_xDlClose_Get(mrb_state *state, mrb_value self) {
    sqlite3_vfs record = drb_ffi__ZTS11sqlite3_vfs_FromRuby(state, self);
    return drb_ffi__ZTSPFvP11sqlite3_vfsPvE_ToRuby(state, record.xDlClose);
}
static mrb_value drb_ffi__ZTS11sqlite3_vfs_xDlClose_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    void (*new_value)(sqlite3_vfs *, void *) = drb_ffi__ZTSPFvP11sqlite3_vfsPvE_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS11sqlite3_vfs *)DATA_PTR(self))->value)->xDlClose = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS11sqlite3_vfs_xRandomness_Get(mrb_state *state, mrb_value self) {
    sqlite3_vfs record = drb_ffi__ZTS11sqlite3_vfs_FromRuby(state, self);
    return drb_ffi__ZTSPFiP11sqlite3_vfsiPcE_ToRuby(state, record.xRandomness);
}
static mrb_value drb_ffi__ZTS11sqlite3_vfs_xRandomness_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int (*new_value)(sqlite3_vfs *, int, char *) = drb_ffi__ZTSPFiP11sqlite3_vfsiPcE_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS11sqlite3_vfs *)DATA_PTR(self))->value)->xRandomness = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS11sqlite3_vfs_xSleep_Get(mrb_state *state, mrb_value self) {
    sqlite3_vfs record = drb_ffi__ZTS11sqlite3_vfs_FromRuby(state, self);
    return drb_ffi__ZTSPFiP11sqlite3_vfsiE_ToRuby(state, record.xSleep);
}
static mrb_value drb_ffi__ZTS11sqlite3_vfs_xSleep_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int (*new_value)(sqlite3_vfs *, int) = drb_ffi__ZTSPFiP11sqlite3_vfsiE_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS11sqlite3_vfs *)DATA_PTR(self))->value)->xSleep = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS11sqlite3_vfs_xCurrentTime_Get(mrb_state *state, mrb_value self) {
    sqlite3_vfs record = drb_ffi__ZTS11sqlite3_vfs_FromRuby(state, self);
    return drb_ffi__ZTSPFiP11sqlite3_vfsPdE_ToRuby(state, record.xCurrentTime);
}
static mrb_value drb_ffi__ZTS11sqlite3_vfs_xCurrentTime_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int (*new_value)(sqlite3_vfs *, double *) = drb_ffi__ZTSPFiP11sqlite3_vfsPdE_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS11sqlite3_vfs *)DATA_PTR(self))->value)->xCurrentTime = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS11sqlite3_vfs_xGetLastError_Get(mrb_state *state, mrb_value self) {
    sqlite3_vfs record = drb_ffi__ZTS11sqlite3_vfs_FromRuby(state, self);
    return drb_ffi__ZTSPFiP11sqlite3_vfsiPcE_ToRuby(state, record.xGetLastError);
}
static mrb_value drb_ffi__ZTS11sqlite3_vfs_xGetLastError_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int (*new_value)(sqlite3_vfs *, int, char *) = drb_ffi__ZTSPFiP11sqlite3_vfsiPcE_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS11sqlite3_vfs *)DATA_PTR(self))->value)->xGetLastError = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS11sqlite3_vfs_xCurrentTimeInt64_Get(mrb_state *state, mrb_value self) {
    sqlite3_vfs record = drb_ffi__ZTS11sqlite3_vfs_FromRuby(state, self);
    return drb_ffi__ZTSPFiP11sqlite3_vfsPxE_ToRuby(state, record.xCurrentTimeInt64);
}
static mrb_value drb_ffi__ZTS11sqlite3_vfs_xCurrentTimeInt64_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int (*new_value)(sqlite3_vfs *, sqlite3_int64 *) = drb_ffi__ZTSPFiP11sqlite3_vfsPxE_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS11sqlite3_vfs *)DATA_PTR(self))->value)->xCurrentTimeInt64 = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS11sqlite3_vfs_xSetSystemCall_Get(mrb_state *state, mrb_value self) {
    sqlite3_vfs record = drb_ffi__ZTS11sqlite3_vfs_FromRuby(state, self);
    return drb_ffi__ZTSPFiP11sqlite3_vfsPKcPFvvEE_ToRuby(state, record.xSetSystemCall);
}
static mrb_value drb_ffi__ZTS11sqlite3_vfs_xSetSystemCall_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int (*new_value)(sqlite3_vfs *, const char *, sqlite3_syscall_ptr) = drb_ffi__ZTSPFiP11sqlite3_vfsPKcPFvvEE_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS11sqlite3_vfs *)DATA_PTR(self))->value)->xSetSystemCall = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS11sqlite3_vfs_xGetSystemCall_Get(mrb_state *state, mrb_value self) {
    sqlite3_vfs record = drb_ffi__ZTS11sqlite3_vfs_FromRuby(state, self);
    return drb_ffi__ZTSPFPFvvEP11sqlite3_vfsPKcE_ToRuby(state, record.xGetSystemCall);
}
static mrb_value drb_ffi__ZTS11sqlite3_vfs_xGetSystemCall_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    sqlite3_syscall_ptr (*new_value)(sqlite3_vfs *, const char *) = drb_ffi__ZTSPFPFvvEP11sqlite3_vfsPKcE_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS11sqlite3_vfs *)DATA_PTR(self))->value)->xGetSystemCall = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS11sqlite3_vfs_xNextSystemCall_Get(mrb_state *state, mrb_value self) {
    sqlite3_vfs record = drb_ffi__ZTS11sqlite3_vfs_FromRuby(state, self);
    return drb_ffi__ZTSPFPKcP11sqlite3_vfsS0_E_ToRuby(state, record.xNextSystemCall);
}
static mrb_value drb_ffi__ZTS11sqlite3_vfs_xNextSystemCall_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    const char *(*new_value)(sqlite3_vfs *, const char *) = drb_ffi__ZTSPFPKcP11sqlite3_vfsS0_E_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS11sqlite3_vfs *)DATA_PTR(self))->value)->xNextSystemCall = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS18sqlite3_index_info_New(mrb_state *state, mrb_value self) {
    struct drb_foreign_object_ZTS18sqlite3_index_info *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS18sqlite3_index_info *));
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3_index_info");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTS18sqlite3_index_info);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTS18sqlite3_index_info_nConstraint_Get(mrb_state *state, mrb_value self) {
    sqlite3_index_info record = drb_ffi__ZTS18sqlite3_index_info_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.nConstraint);
}
static mrb_value drb_ffi__ZTS18sqlite3_index_info_nConstraint_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS18sqlite3_index_info *)DATA_PTR(self))->value)->nConstraint = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS18sqlite3_index_info_aConstraint_Get(mrb_state *state, mrb_value self) {
    sqlite3_index_info record = drb_ffi__ZTS18sqlite3_index_info_FromRuby(state, self);
    return drb_ffi__ZTSP24sqlite3_index_constraint_ToRuby(state, record.aConstraint);
}
static mrb_value drb_ffi__ZTS18sqlite3_index_info_aConstraint_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    struct sqlite3_index_constraint *new_value = drb_ffi__ZTSP24sqlite3_index_constraint_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS18sqlite3_index_info *)DATA_PTR(self))->value)->aConstraint = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS18sqlite3_index_info_nOrderBy_Get(mrb_state *state, mrb_value self) {
    sqlite3_index_info record = drb_ffi__ZTS18sqlite3_index_info_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.nOrderBy);
}
static mrb_value drb_ffi__ZTS18sqlite3_index_info_nOrderBy_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS18sqlite3_index_info *)DATA_PTR(self))->value)->nOrderBy = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS18sqlite3_index_info_aOrderBy_Get(mrb_state *state, mrb_value self) {
    sqlite3_index_info record = drb_ffi__ZTS18sqlite3_index_info_FromRuby(state, self);
    return drb_ffi__ZTSP21sqlite3_index_orderby_ToRuby(state, record.aOrderBy);
}
static mrb_value drb_ffi__ZTS18sqlite3_index_info_aOrderBy_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    struct sqlite3_index_orderby *new_value = drb_ffi__ZTSP21sqlite3_index_orderby_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS18sqlite3_index_info *)DATA_PTR(self))->value)->aOrderBy = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS18sqlite3_index_info_aConstraintUsage_Get(mrb_state *state, mrb_value self) {
    sqlite3_index_info record = drb_ffi__ZTS18sqlite3_index_info_FromRuby(state, self);
    return drb_ffi__ZTSP30sqlite3_index_constraint_usage_ToRuby(state, record.aConstraintUsage);
}
static mrb_value drb_ffi__ZTS18sqlite3_index_info_aConstraintUsage_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    struct sqlite3_index_constraint_usage *new_value = drb_ffi__ZTSP30sqlite3_index_constraint_usage_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS18sqlite3_index_info *)DATA_PTR(self))->value)->aConstraintUsage = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS18sqlite3_index_info_idxNum_Get(mrb_state *state, mrb_value self) {
    sqlite3_index_info record = drb_ffi__ZTS18sqlite3_index_info_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.idxNum);
}
static mrb_value drb_ffi__ZTS18sqlite3_index_info_idxNum_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS18sqlite3_index_info *)DATA_PTR(self))->value)->idxNum = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS18sqlite3_index_info_idxStr_Get(mrb_state *state, mrb_value self) {
    sqlite3_index_info record = drb_ffi__ZTS18sqlite3_index_info_FromRuby(state, self);
    return drb_ffi__ZTSPc_ToRuby(state, record.idxStr);
}
static mrb_value drb_ffi__ZTS18sqlite3_index_info_idxStr_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    char *new_value = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS18sqlite3_index_info *)DATA_PTR(self))->value)->idxStr = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS18sqlite3_index_info_needToFreeIdxStr_Get(mrb_state *state, mrb_value self) {
    sqlite3_index_info record = drb_ffi__ZTS18sqlite3_index_info_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.needToFreeIdxStr);
}
static mrb_value drb_ffi__ZTS18sqlite3_index_info_needToFreeIdxStr_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS18sqlite3_index_info *)DATA_PTR(self))->value)->needToFreeIdxStr = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS18sqlite3_index_info_orderByConsumed_Get(mrb_state *state, mrb_value self) {
    sqlite3_index_info record = drb_ffi__ZTS18sqlite3_index_info_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.orderByConsumed);
}
static mrb_value drb_ffi__ZTS18sqlite3_index_info_orderByConsumed_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS18sqlite3_index_info *)DATA_PTR(self))->value)->orderByConsumed = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS18sqlite3_index_info_estimatedCost_Get(mrb_state *state, mrb_value self) {
    sqlite3_index_info record = drb_ffi__ZTS18sqlite3_index_info_FromRuby(state, self);
    return drb_ffi__ZTSd_ToRuby(state, record.estimatedCost);
}
static mrb_value drb_ffi__ZTS18sqlite3_index_info_estimatedCost_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    double new_value = drb_ffi__ZTSd_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS18sqlite3_index_info *)DATA_PTR(self))->value)->estimatedCost = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS18sqlite3_index_info_estimatedRows_Get(mrb_state *state, mrb_value self) {
    sqlite3_index_info record = drb_ffi__ZTS18sqlite3_index_info_FromRuby(state, self);
    return drb_ffi__ZTSx_ToRuby(state, record.estimatedRows);
}
static mrb_value drb_ffi__ZTS18sqlite3_index_info_estimatedRows_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    sqlite3_int64 new_value = drb_ffi__ZTSx_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS18sqlite3_index_info *)DATA_PTR(self))->value)->estimatedRows = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS18sqlite3_index_info_idxFlags_Get(mrb_state *state, mrb_value self) {
    sqlite3_index_info record = drb_ffi__ZTS18sqlite3_index_info_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.idxFlags);
}
static mrb_value drb_ffi__ZTS18sqlite3_index_info_idxFlags_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS18sqlite3_index_info *)DATA_PTR(self))->value)->idxFlags = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS18sqlite3_index_info_colUsed_Get(mrb_state *state, mrb_value self) {
    sqlite3_index_info record = drb_ffi__ZTS18sqlite3_index_info_FromRuby(state, self);
    return drb_ffi__ZTSy_ToRuby(state, record.colUsed);
}
static mrb_value drb_ffi__ZTS18sqlite3_index_info_colUsed_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    sqlite3_uint64 new_value = drb_ffi__ZTSy_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS18sqlite3_index_info *)DATA_PTR(self))->value)->colUsed = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS18sqlite3_io_methods_New(mrb_state *state, mrb_value self) {
    struct drb_foreign_object_ZTS18sqlite3_io_methods *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS18sqlite3_io_methods *));
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3_io_methods");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTS18sqlite3_io_methods);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTS18sqlite3_io_methods_iVersion_Get(mrb_state *state, mrb_value self) {
    struct sqlite3_io_methods record = drb_ffi__ZTS18sqlite3_io_methods_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.iVersion);
}
static mrb_value drb_ffi__ZTS18sqlite3_io_methods_iVersion_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS18sqlite3_io_methods *)DATA_PTR(self))->value)->iVersion = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS18sqlite3_io_methods_xClose_Get(mrb_state *state, mrb_value self) {
    struct sqlite3_io_methods record = drb_ffi__ZTS18sqlite3_io_methods_FromRuby(state, self);
    return drb_ffi__ZTSPFiP12sqlite3_fileE_ToRuby(state, record.xClose);
}
static mrb_value drb_ffi__ZTS18sqlite3_io_methods_xClose_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int (*new_value)(sqlite3_file *) = drb_ffi__ZTSPFiP12sqlite3_fileE_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS18sqlite3_io_methods *)DATA_PTR(self))->value)->xClose = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS18sqlite3_io_methods_xRead_Get(mrb_state *state, mrb_value self) {
    struct sqlite3_io_methods record = drb_ffi__ZTS18sqlite3_io_methods_FromRuby(state, self);
    return drb_ffi__ZTSPFiP12sqlite3_filePvixE_ToRuby(state, record.xRead);
}
static mrb_value drb_ffi__ZTS18sqlite3_io_methods_xRead_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int (*new_value)(sqlite3_file *, void *, int, sqlite3_int64) = drb_ffi__ZTSPFiP12sqlite3_filePvixE_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS18sqlite3_io_methods *)DATA_PTR(self))->value)->xRead = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS18sqlite3_io_methods_xWrite_Get(mrb_state *state, mrb_value self) {
    struct sqlite3_io_methods record = drb_ffi__ZTS18sqlite3_io_methods_FromRuby(state, self);
    return drb_ffi__ZTSPFiP12sqlite3_filePKvixE_ToRuby(state, record.xWrite);
}
static mrb_value drb_ffi__ZTS18sqlite3_io_methods_xWrite_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int (*new_value)(sqlite3_file *, const void *, int, sqlite3_int64) = drb_ffi__ZTSPFiP12sqlite3_filePKvixE_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS18sqlite3_io_methods *)DATA_PTR(self))->value)->xWrite = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS18sqlite3_io_methods_xTruncate_Get(mrb_state *state, mrb_value self) {
    struct sqlite3_io_methods record = drb_ffi__ZTS18sqlite3_io_methods_FromRuby(state, self);
    return drb_ffi__ZTSPFiP12sqlite3_filexE_ToRuby(state, record.xTruncate);
}
static mrb_value drb_ffi__ZTS18sqlite3_io_methods_xTruncate_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int (*new_value)(sqlite3_file *, sqlite3_int64) = drb_ffi__ZTSPFiP12sqlite3_filexE_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS18sqlite3_io_methods *)DATA_PTR(self))->value)->xTruncate = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS18sqlite3_io_methods_xSync_Get(mrb_state *state, mrb_value self) {
    struct sqlite3_io_methods record = drb_ffi__ZTS18sqlite3_io_methods_FromRuby(state, self);
    return drb_ffi__ZTSPFiP12sqlite3_fileiE_ToRuby(state, record.xSync);
}
static mrb_value drb_ffi__ZTS18sqlite3_io_methods_xSync_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int (*new_value)(sqlite3_file *, int) = drb_ffi__ZTSPFiP12sqlite3_fileiE_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS18sqlite3_io_methods *)DATA_PTR(self))->value)->xSync = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS18sqlite3_io_methods_xFileSize_Get(mrb_state *state, mrb_value self) {
    struct sqlite3_io_methods record = drb_ffi__ZTS18sqlite3_io_methods_FromRuby(state, self);
    return drb_ffi__ZTSPFiP12sqlite3_filePxE_ToRuby(state, record.xFileSize);
}
static mrb_value drb_ffi__ZTS18sqlite3_io_methods_xFileSize_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int (*new_value)(sqlite3_file *, sqlite3_int64 *) = drb_ffi__ZTSPFiP12sqlite3_filePxE_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS18sqlite3_io_methods *)DATA_PTR(self))->value)->xFileSize = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS18sqlite3_io_methods_xLock_Get(mrb_state *state, mrb_value self) {
    struct sqlite3_io_methods record = drb_ffi__ZTS18sqlite3_io_methods_FromRuby(state, self);
    return drb_ffi__ZTSPFiP12sqlite3_fileiE_ToRuby(state, record.xLock);
}
static mrb_value drb_ffi__ZTS18sqlite3_io_methods_xLock_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int (*new_value)(sqlite3_file *, int) = drb_ffi__ZTSPFiP12sqlite3_fileiE_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS18sqlite3_io_methods *)DATA_PTR(self))->value)->xLock = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS18sqlite3_io_methods_xUnlock_Get(mrb_state *state, mrb_value self) {
    struct sqlite3_io_methods record = drb_ffi__ZTS18sqlite3_io_methods_FromRuby(state, self);
    return drb_ffi__ZTSPFiP12sqlite3_fileiE_ToRuby(state, record.xUnlock);
}
static mrb_value drb_ffi__ZTS18sqlite3_io_methods_xUnlock_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int (*new_value)(sqlite3_file *, int) = drb_ffi__ZTSPFiP12sqlite3_fileiE_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS18sqlite3_io_methods *)DATA_PTR(self))->value)->xUnlock = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS18sqlite3_io_methods_xCheckReservedLock_Get(mrb_state *state, mrb_value self) {
    struct sqlite3_io_methods record = drb_ffi__ZTS18sqlite3_io_methods_FromRuby(state, self);
    return drb_ffi__ZTSPFiP12sqlite3_filePiE_ToRuby(state, record.xCheckReservedLock);
}
static mrb_value drb_ffi__ZTS18sqlite3_io_methods_xCheckReservedLock_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int (*new_value)(sqlite3_file *, int *) = drb_ffi__ZTSPFiP12sqlite3_filePiE_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS18sqlite3_io_methods *)DATA_PTR(self))->value)->xCheckReservedLock = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS18sqlite3_io_methods_xFileControl_Get(mrb_state *state, mrb_value self) {
    struct sqlite3_io_methods record = drb_ffi__ZTS18sqlite3_io_methods_FromRuby(state, self);
    return drb_ffi__ZTSPFiP12sqlite3_fileiPvE_ToRuby(state, record.xFileControl);
}
static mrb_value drb_ffi__ZTS18sqlite3_io_methods_xFileControl_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int (*new_value)(sqlite3_file *, int, void *) = drb_ffi__ZTSPFiP12sqlite3_fileiPvE_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS18sqlite3_io_methods *)DATA_PTR(self))->value)->xFileControl = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS18sqlite3_io_methods_xSectorSize_Get(mrb_state *state, mrb_value self) {
    struct sqlite3_io_methods record = drb_ffi__ZTS18sqlite3_io_methods_FromRuby(state, self);
    return drb_ffi__ZTSPFiP12sqlite3_fileE_ToRuby(state, record.xSectorSize);
}
static mrb_value drb_ffi__ZTS18sqlite3_io_methods_xSectorSize_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int (*new_value)(sqlite3_file *) = drb_ffi__ZTSPFiP12sqlite3_fileE_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS18sqlite3_io_methods *)DATA_PTR(self))->value)->xSectorSize = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS18sqlite3_io_methods_xDeviceCharacteristics_Get(mrb_state *state, mrb_value self) {
    struct sqlite3_io_methods record = drb_ffi__ZTS18sqlite3_io_methods_FromRuby(state, self);
    return drb_ffi__ZTSPFiP12sqlite3_fileE_ToRuby(state, record.xDeviceCharacteristics);
}
static mrb_value drb_ffi__ZTS18sqlite3_io_methods_xDeviceCharacteristics_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int (*new_value)(sqlite3_file *) = drb_ffi__ZTSPFiP12sqlite3_fileE_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS18sqlite3_io_methods *)DATA_PTR(self))->value)->xDeviceCharacteristics = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS18sqlite3_io_methods_xShmMap_Get(mrb_state *state, mrb_value self) {
    struct sqlite3_io_methods record = drb_ffi__ZTS18sqlite3_io_methods_FromRuby(state, self);
    return drb_ffi__ZTSPFiP12sqlite3_fileiiiPPVvE_ToRuby(state, record.xShmMap);
}
static mrb_value drb_ffi__ZTS18sqlite3_io_methods_xShmMap_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int (*new_value)(sqlite3_file *, int, int, int, volatile void **) = drb_ffi__ZTSPFiP12sqlite3_fileiiiPPVvE_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS18sqlite3_io_methods *)DATA_PTR(self))->value)->xShmMap = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS18sqlite3_io_methods_xShmLock_Get(mrb_state *state, mrb_value self) {
    struct sqlite3_io_methods record = drb_ffi__ZTS18sqlite3_io_methods_FromRuby(state, self);
    return drb_ffi__ZTSPFiP12sqlite3_fileiiiE_ToRuby(state, record.xShmLock);
}
static mrb_value drb_ffi__ZTS18sqlite3_io_methods_xShmLock_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int (*new_value)(sqlite3_file *, int, int, int) = drb_ffi__ZTSPFiP12sqlite3_fileiiiE_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS18sqlite3_io_methods *)DATA_PTR(self))->value)->xShmLock = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS18sqlite3_io_methods_xShmBarrier_Get(mrb_state *state, mrb_value self) {
    struct sqlite3_io_methods record = drb_ffi__ZTS18sqlite3_io_methods_FromRuby(state, self);
    return drb_ffi__ZTSPFvP12sqlite3_fileE_ToRuby(state, record.xShmBarrier);
}
static mrb_value drb_ffi__ZTS18sqlite3_io_methods_xShmBarrier_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    void (*new_value)(sqlite3_file *) = drb_ffi__ZTSPFvP12sqlite3_fileE_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS18sqlite3_io_methods *)DATA_PTR(self))->value)->xShmBarrier = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS18sqlite3_io_methods_xShmUnmap_Get(mrb_state *state, mrb_value self) {
    struct sqlite3_io_methods record = drb_ffi__ZTS18sqlite3_io_methods_FromRuby(state, self);
    return drb_ffi__ZTSPFiP12sqlite3_fileiE_ToRuby(state, record.xShmUnmap);
}
static mrb_value drb_ffi__ZTS18sqlite3_io_methods_xShmUnmap_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int (*new_value)(sqlite3_file *, int) = drb_ffi__ZTSPFiP12sqlite3_fileiE_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS18sqlite3_io_methods *)DATA_PTR(self))->value)->xShmUnmap = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS18sqlite3_io_methods_xFetch_Get(mrb_state *state, mrb_value self) {
    struct sqlite3_io_methods record = drb_ffi__ZTS18sqlite3_io_methods_FromRuby(state, self);
    return drb_ffi__ZTSPFiP12sqlite3_filexiPPvE_ToRuby(state, record.xFetch);
}
static mrb_value drb_ffi__ZTS18sqlite3_io_methods_xFetch_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int (*new_value)(sqlite3_file *, sqlite3_int64, int, void **) = drb_ffi__ZTSPFiP12sqlite3_filexiPPvE_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS18sqlite3_io_methods *)DATA_PTR(self))->value)->xFetch = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS18sqlite3_io_methods_xUnfetch_Get(mrb_state *state, mrb_value self) {
    struct sqlite3_io_methods record = drb_ffi__ZTS18sqlite3_io_methods_FromRuby(state, self);
    return drb_ffi__ZTSPFiP12sqlite3_filexPvE_ToRuby(state, record.xUnfetch);
}
static mrb_value drb_ffi__ZTS18sqlite3_io_methods_xUnfetch_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int (*new_value)(sqlite3_file *, sqlite3_int64, void *) = drb_ffi__ZTSPFiP12sqlite3_filexPvE_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS18sqlite3_io_methods *)DATA_PTR(self))->value)->xUnfetch = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS24sqlite3_index_constraint_New(mrb_state *state, mrb_value self) {
    struct drb_foreign_object_ZTS24sqlite3_index_constraint *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS24sqlite3_index_constraint *));
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3_index_constraint");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTS24sqlite3_index_constraint);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTS24sqlite3_index_constraint_iColumn_Get(mrb_state *state, mrb_value self) {
    struct sqlite3_index_constraint record = drb_ffi__ZTS24sqlite3_index_constraint_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.iColumn);
}
static mrb_value drb_ffi__ZTS24sqlite3_index_constraint_iColumn_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS24sqlite3_index_constraint *)DATA_PTR(self))->value)->iColumn = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS24sqlite3_index_constraint_op_Get(mrb_state *state, mrb_value self) {
    struct sqlite3_index_constraint record = drb_ffi__ZTS24sqlite3_index_constraint_FromRuby(state, self);
    return drb_ffi__ZTSh_ToRuby(state, record.op);
}
static mrb_value drb_ffi__ZTS24sqlite3_index_constraint_op_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    unsigned char new_value = drb_ffi__ZTSh_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS24sqlite3_index_constraint *)DATA_PTR(self))->value)->op = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS24sqlite3_index_constraint_usable_Get(mrb_state *state, mrb_value self) {
    struct sqlite3_index_constraint record = drb_ffi__ZTS24sqlite3_index_constraint_FromRuby(state, self);
    return drb_ffi__ZTSh_ToRuby(state, record.usable);
}
static mrb_value drb_ffi__ZTS24sqlite3_index_constraint_usable_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    unsigned char new_value = drb_ffi__ZTSh_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS24sqlite3_index_constraint *)DATA_PTR(self))->value)->usable = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS24sqlite3_index_constraint_iTermOffset_Get(mrb_state *state, mrb_value self) {
    struct sqlite3_index_constraint record = drb_ffi__ZTS24sqlite3_index_constraint_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.iTermOffset);
}
static mrb_value drb_ffi__ZTS24sqlite3_index_constraint_iTermOffset_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS24sqlite3_index_constraint *)DATA_PTR(self))->value)->iTermOffset = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS21sqlite3_index_orderby_New(mrb_state *state, mrb_value self) {
    struct drb_foreign_object_ZTS21sqlite3_index_orderby *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS21sqlite3_index_orderby *));
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3_index_orderby");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTS21sqlite3_index_orderby);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTS21sqlite3_index_orderby_iColumn_Get(mrb_state *state, mrb_value self) {
    struct sqlite3_index_orderby record = drb_ffi__ZTS21sqlite3_index_orderby_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.iColumn);
}
static mrb_value drb_ffi__ZTS21sqlite3_index_orderby_iColumn_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS21sqlite3_index_orderby *)DATA_PTR(self))->value)->iColumn = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS21sqlite3_index_orderby_desc_Get(mrb_state *state, mrb_value self) {
    struct sqlite3_index_orderby record = drb_ffi__ZTS21sqlite3_index_orderby_FromRuby(state, self);
    return drb_ffi__ZTSh_ToRuby(state, record.desc);
}
static mrb_value drb_ffi__ZTS21sqlite3_index_orderby_desc_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    unsigned char new_value = drb_ffi__ZTSh_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS21sqlite3_index_orderby *)DATA_PTR(self))->value)->desc = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS30sqlite3_index_constraint_usage_New(mrb_state *state, mrb_value self) {
    struct drb_foreign_object_ZTS30sqlite3_index_constraint_usage *ptr = calloc(1, sizeof(struct drb_foreign_object_ZTS30sqlite3_index_constraint_usage *));
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_module_get_under(state, FFI, "LIBSQLITE3");
    struct RClass *klass = drb_api->mrb_class_get_under(state, module, "Sqlite3_index_constraint_usage");
    struct RData *rdata = drb_api->mrb_data_object_alloc(state, klass, ptr, &ForeignObjectType_ZTS30sqlite3_index_constraint_usage);
    return mrb_obj_value(rdata);
}
static mrb_value drb_ffi__ZTS30sqlite3_index_constraint_usage_argvIndex_Get(mrb_state *state, mrb_value self) {
    struct sqlite3_index_constraint_usage record = drb_ffi__ZTS30sqlite3_index_constraint_usage_FromRuby(state, self);
    return drb_ffi__ZTSi_ToRuby(state, record.argvIndex);
}
static mrb_value drb_ffi__ZTS30sqlite3_index_constraint_usage_argvIndex_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    int new_value = drb_ffi__ZTSi_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS30sqlite3_index_constraint_usage *)DATA_PTR(self))->value)->argvIndex = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi__ZTS30sqlite3_index_constraint_usage_omit_Get(mrb_state *state, mrb_value self) {
    struct sqlite3_index_constraint_usage record = drb_ffi__ZTS30sqlite3_index_constraint_usage_FromRuby(state, self);
    return drb_ffi__ZTSh_ToRuby(state, record.omit);
}
static mrb_value drb_ffi__ZTS30sqlite3_index_constraint_usage_omit_Set(mrb_state *state, mrb_value self) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    unsigned char new_value = drb_ffi__ZTSh_FromRuby(state, args[0]);
    (&((struct drb_foreign_object_ZTS30sqlite3_index_constraint_usage *)DATA_PTR(self))->value)->omit = new_value;
    return mrb_nil_value();
}
static mrb_value drb_ffi___debugbreak_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 0)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'__debugbreak': wrong number of arguments (%d for 0)", argc);
    __debugbreak();
    return mrb_nil_value();
}
static mrb_value drb_ffi___mingw_get_crt_info_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 0)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'__mingw_get_crt_info': wrong number of arguments (%d for 0)", argc);
    char *ret_val = __mingw_get_crt_info();
    return drb_ffi__ZTSPc_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_libversion_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 0)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_libversion': wrong number of arguments (%d for 0)", argc);
    char *ret_val = sqlite3_libversion();
    return drb_ffi__ZTSPc_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_sourceid_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 0)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_sourceid': wrong number of arguments (%d for 0)", argc);
    char *ret_val = sqlite3_sourceid();
    return drb_ffi__ZTSPc_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_libversion_number_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 0)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_libversion_number': wrong number of arguments (%d for 0)", argc);
    int ret_val = sqlite3_libversion_number();
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_compileoption_used_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_compileoption_used': wrong number of arguments (%d for 1)", argc);
    char *zOptName_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    int ret_val = sqlite3_compileoption_used(zOptName_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_compileoption_get_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_compileoption_get': wrong number of arguments (%d for 1)", argc);
    int N_0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    char *ret_val = sqlite3_compileoption_get(N_0);
    return drb_ffi__ZTSPc_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_threadsafe_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 0)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_threadsafe': wrong number of arguments (%d for 0)", argc);
    int ret_val = sqlite3_threadsafe();
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_close_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_close': wrong number of arguments (%d for 1)", argc);
    sqlite3 *_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    int ret_val = sqlite3_close(_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_close_v2_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_close_v2': wrong number of arguments (%d for 1)", argc);
    sqlite3 *_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    int ret_val = sqlite3_close_v2(_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_exec_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 5)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_exec': wrong number of arguments (%d for 5)", argc);
    sqlite3 *_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    char *sql_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    int (*callback_2)(void *, int, char **, char **) = drb_ffi__ZTSPFiPviPPcS1_E_FromRuby(state, args[2]);
    void *_3 = drb_ffi__ZTSPv_FromRuby(state, args[3]);
    char **errmsg_4 = drb_ffi__ZTSPPc_FromRuby(state, args[4]);
    int ret_val = sqlite3_exec(_0, sql_1, callback_2, _3, errmsg_4);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_initialize_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 0)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_initialize': wrong number of arguments (%d for 0)", argc);
    int ret_val = sqlite3_initialize();
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_shutdown_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 0)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_shutdown': wrong number of arguments (%d for 0)", argc);
    int ret_val = sqlite3_shutdown();
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_os_init_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 0)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_os_init': wrong number of arguments (%d for 0)", argc);
    int ret_val = sqlite3_os_init();
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_os_end_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 0)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_os_end': wrong number of arguments (%d for 0)", argc);
    int ret_val = sqlite3_os_end();
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_extended_result_codes_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_extended_result_codes': wrong number of arguments (%d for 2)", argc);
    sqlite3 *_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    int onoff_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    int ret_val = sqlite3_extended_result_codes(_0, onoff_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_last_insert_rowid_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_last_insert_rowid': wrong number of arguments (%d for 1)", argc);
    sqlite3 *_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    sqlite3_int64 ret_val = sqlite3_last_insert_rowid(_0);
    return drb_ffi__ZTSx_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_set_last_insert_rowid_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_set_last_insert_rowid': wrong number of arguments (%d for 2)", argc);
    sqlite3 *_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    sqlite3_int64 _1 = drb_ffi__ZTSx_FromRuby(state, args[1]);
    sqlite3_set_last_insert_rowid(_0, _1);
    return mrb_nil_value();
}
static mrb_value drb_ffi_sqlite3_changes_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_changes': wrong number of arguments (%d for 1)", argc);
    sqlite3 *_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    int ret_val = sqlite3_changes(_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_changes64_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_changes64': wrong number of arguments (%d for 1)", argc);
    sqlite3 *_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    sqlite3_int64 ret_val = sqlite3_changes64(_0);
    return drb_ffi__ZTSx_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_total_changes_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_total_changes': wrong number of arguments (%d for 1)", argc);
    sqlite3 *_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    int ret_val = sqlite3_total_changes(_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_total_changes64_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_total_changes64': wrong number of arguments (%d for 1)", argc);
    sqlite3 *_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    sqlite3_int64 ret_val = sqlite3_total_changes64(_0);
    return drb_ffi__ZTSx_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_interrupt_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_interrupt': wrong number of arguments (%d for 1)", argc);
    sqlite3 *_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    sqlite3_interrupt(_0);
    return mrb_nil_value();
}
static mrb_value drb_ffi_sqlite3_complete_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_complete': wrong number of arguments (%d for 1)", argc);
    char *sql_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    int ret_val = sqlite3_complete(sql_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_complete16_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_complete16': wrong number of arguments (%d for 1)", argc);
    void *sql_0 = drb_ffi__ZTSPv_FromRuby(state, args[0]);
    int ret_val = sqlite3_complete16(sql_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_busy_handler_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_busy_handler': wrong number of arguments (%d for 3)", argc);
    sqlite3 *_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    int (*_1)(void *, int) = drb_ffi__ZTSPFiPviE_FromRuby(state, args[1]);
    void *_2 = drb_ffi__ZTSPv_FromRuby(state, args[2]);
    int ret_val = sqlite3_busy_handler(_0, _1, _2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_busy_timeout_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_busy_timeout': wrong number of arguments (%d for 2)", argc);
    sqlite3 *_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    int ms_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    int ret_val = sqlite3_busy_timeout(_0, ms_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_get_table_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 6)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_get_table': wrong number of arguments (%d for 6)", argc);
    sqlite3 *db_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    char *zSql_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    char ***pazResult_2 = drb_ffi__ZTSPPPc_FromRuby(state, args[2]);
    int *pnRow_3 = drb_ffi__ZTSPi_FromRuby(state, args[3]);
    int *pnColumn_4 = drb_ffi__ZTSPi_FromRuby(state, args[4]);
    char **pzErrmsg_5 = drb_ffi__ZTSPPc_FromRuby(state, args[5]);
    int ret_val = sqlite3_get_table(db_0, zSql_1, pazResult_2, pnRow_3, pnColumn_4, pzErrmsg_5);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_free_table_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_free_table': wrong number of arguments (%d for 1)", argc);
    char **result_0 = drb_ffi__ZTSPPc_FromRuby(state, args[0]);
    sqlite3_free_table(result_0);
    return mrb_nil_value();
}
static mrb_value drb_ffi_sqlite3_vmprintf_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_vmprintf': wrong number of arguments (%d for 2)", argc);
    char *_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    char *_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    char *ret_val = sqlite3_vmprintf(_0, _1);
    return drb_ffi__ZTSPc_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_vsnprintf_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 4)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_vsnprintf': wrong number of arguments (%d for 4)", argc);
    int _0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    char *_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    char *_2 = drb_ffi__ZTSPc_FromRuby(state, args[2]);
    char *_3 = drb_ffi__ZTSPc_FromRuby(state, args[3]);
    char *ret_val = sqlite3_vsnprintf(_0, _1, _2, _3);
    return drb_ffi__ZTSPc_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_malloc_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_malloc': wrong number of arguments (%d for 1)", argc);
    int _0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    void *ret_val = sqlite3_malloc(_0);
    return drb_ffi__ZTSPv_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_malloc64_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_malloc64': wrong number of arguments (%d for 1)", argc);
    sqlite3_uint64 _0 = drb_ffi__ZTSy_FromRuby(state, args[0]);
    void *ret_val = sqlite3_malloc64(_0);
    return drb_ffi__ZTSPv_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_realloc_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_realloc': wrong number of arguments (%d for 2)", argc);
    void *_0 = drb_ffi__ZTSPv_FromRuby(state, args[0]);
    int _1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    void *ret_val = sqlite3_realloc(_0, _1);
    return drb_ffi__ZTSPv_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_realloc64_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_realloc64': wrong number of arguments (%d for 2)", argc);
    void *_0 = drb_ffi__ZTSPv_FromRuby(state, args[0]);
    sqlite3_uint64 _1 = drb_ffi__ZTSy_FromRuby(state, args[1]);
    void *ret_val = sqlite3_realloc64(_0, _1);
    return drb_ffi__ZTSPv_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_free_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_free': wrong number of arguments (%d for 1)", argc);
    void *_0 = drb_ffi__ZTSPv_FromRuby(state, args[0]);
    sqlite3_free(_0);
    return mrb_nil_value();
}
static mrb_value drb_ffi_sqlite3_msize_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_msize': wrong number of arguments (%d for 1)", argc);
    void *_0 = drb_ffi__ZTSPv_FromRuby(state, args[0]);
    sqlite3_uint64 ret_val = sqlite3_msize(_0);
    return drb_ffi__ZTSy_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_memory_used_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 0)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_memory_used': wrong number of arguments (%d for 0)", argc);
    sqlite3_int64 ret_val = sqlite3_memory_used();
    return drb_ffi__ZTSx_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_memory_highwater_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_memory_highwater': wrong number of arguments (%d for 1)", argc);
    int resetFlag_0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    sqlite3_int64 ret_val = sqlite3_memory_highwater(resetFlag_0);
    return drb_ffi__ZTSx_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_randomness_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_randomness': wrong number of arguments (%d for 2)", argc);
    int N_0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    void *P_1 = drb_ffi__ZTSPv_FromRuby(state, args[1]);
    sqlite3_randomness(N_0, P_1);
    return mrb_nil_value();
}
static mrb_value drb_ffi_sqlite3_set_authorizer_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_set_authorizer': wrong number of arguments (%d for 3)", argc);
    sqlite3 *_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    int (*xAuth_1)(void *, int, const char *, const char *, const char *, const char *) = drb_ffi__ZTSPFiPviPKcS1_S1_S1_E_FromRuby(state, args[1]);
    void *pUserData_2 = drb_ffi__ZTSPv_FromRuby(state, args[2]);
    int ret_val = sqlite3_set_authorizer(_0, xAuth_1, pUserData_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_trace_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_trace': wrong number of arguments (%d for 3)", argc);
    sqlite3 *_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    void (*xTrace_1)(void *, const char *) = drb_ffi__ZTSPFvPvPKcE_FromRuby(state, args[1]);
    void *_2 = drb_ffi__ZTSPv_FromRuby(state, args[2]);
    void *ret_val = sqlite3_trace(_0, xTrace_1, _2);
    return drb_ffi__ZTSPv_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_profile_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_profile': wrong number of arguments (%d for 3)", argc);
    sqlite3 *_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    void (*xProfile_1)(void *, const char *, sqlite3_uint64) = drb_ffi__ZTSPFvPvPKcyE_FromRuby(state, args[1]);
    void *_2 = drb_ffi__ZTSPv_FromRuby(state, args[2]);
    void *ret_val = sqlite3_profile(_0, xProfile_1, _2);
    return drb_ffi__ZTSPv_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_trace_v2_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 4)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_trace_v2': wrong number of arguments (%d for 4)", argc);
    sqlite3 *_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    unsigned int uMask_1 = drb_ffi__ZTSj_FromRuby(state, args[1]);
    int (*xCallback_2)(unsigned int, void *, void *, void *) = drb_ffi__ZTSPFijPvS_S_E_FromRuby(state, args[2]);
    void *pCtx_3 = drb_ffi__ZTSPv_FromRuby(state, args[3]);
    int ret_val = sqlite3_trace_v2(_0, uMask_1, xCallback_2, pCtx_3);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_progress_handler_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 4)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_progress_handler': wrong number of arguments (%d for 4)", argc);
    sqlite3 *_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    int _1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    int (*_2)(void *) = drb_ffi__ZTSPFiPvE_FromRuby(state, args[2]);
    void *_3 = drb_ffi__ZTSPv_FromRuby(state, args[3]);
    sqlite3_progress_handler(_0, _1, _2, _3);
    return mrb_nil_value();
}
static mrb_value drb_ffi_sqlite3_open_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_open': wrong number of arguments (%d for 2)", argc);
    char *filename_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    sqlite3 **ppDb_1 = drb_ffi__ZTSPP7sqlite3_FromRuby(state, args[1]);
    int ret_val = sqlite3_open(filename_0, ppDb_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_open16_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_open16': wrong number of arguments (%d for 2)", argc);
    void *filename_0 = drb_ffi__ZTSPv_FromRuby(state, args[0]);
    sqlite3 **ppDb_1 = drb_ffi__ZTSPP7sqlite3_FromRuby(state, args[1]);
    int ret_val = sqlite3_open16(filename_0, ppDb_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_open_v2_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 4)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_open_v2': wrong number of arguments (%d for 4)", argc);
    char *filename_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    sqlite3 **ppDb_1 = drb_ffi__ZTSPP7sqlite3_FromRuby(state, args[1]);
    int flags_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    char *zVfs_3 = drb_ffi__ZTSPc_FromRuby(state, args[3]);
    int ret_val = sqlite3_open_v2(filename_0, ppDb_1, flags_2, zVfs_3);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_uri_parameter_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_uri_parameter': wrong number of arguments (%d for 2)", argc);
    char *zFilename_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    char *zParam_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    char *ret_val = sqlite3_uri_parameter(zFilename_0, zParam_1);
    return drb_ffi__ZTSPc_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_uri_boolean_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_uri_boolean': wrong number of arguments (%d for 3)", argc);
    char *zFile_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    char *zParam_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    int bDefault_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    int ret_val = sqlite3_uri_boolean(zFile_0, zParam_1, bDefault_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_uri_int64_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_uri_int64': wrong number of arguments (%d for 3)", argc);
    char *_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    char *_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    sqlite3_int64 _2 = drb_ffi__ZTSx_FromRuby(state, args[2]);
    sqlite3_int64 ret_val = sqlite3_uri_int64(_0, _1, _2);
    return drb_ffi__ZTSx_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_uri_key_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_uri_key': wrong number of arguments (%d for 2)", argc);
    char *zFilename_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    int N_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    char *ret_val = sqlite3_uri_key(zFilename_0, N_1);
    return drb_ffi__ZTSPc_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_filename_database_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_filename_database': wrong number of arguments (%d for 1)", argc);
    char *_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    char *ret_val = sqlite3_filename_database(_0);
    return drb_ffi__ZTSPc_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_filename_journal_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_filename_journal': wrong number of arguments (%d for 1)", argc);
    char *_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    char *ret_val = sqlite3_filename_journal(_0);
    return drb_ffi__ZTSPc_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_filename_wal_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_filename_wal': wrong number of arguments (%d for 1)", argc);
    char *_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    char *ret_val = sqlite3_filename_wal(_0);
    return drb_ffi__ZTSPc_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_database_file_object_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_database_file_object': wrong number of arguments (%d for 1)", argc);
    char *_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    sqlite3_file *ret_val = sqlite3_database_file_object(_0);
    return drb_ffi__ZTSP12sqlite3_file_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_create_filename_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 5)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_create_filename': wrong number of arguments (%d for 5)", argc);
    char *zDatabase_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    char *zJournal_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    char *zWal_2 = drb_ffi__ZTSPc_FromRuby(state, args[2]);
    int nParam_3 = drb_ffi__ZTSi_FromRuby(state, args[3]);
    char **azParam_4 = drb_ffi__ZTSPPc_FromRuby(state, args[4]);
    char *ret_val = sqlite3_create_filename(zDatabase_0, zJournal_1, zWal_2, nParam_3, azParam_4);
    return drb_ffi__ZTSPc_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_free_filename_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_free_filename': wrong number of arguments (%d for 1)", argc);
    char *_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    sqlite3_free_filename(_0);
    return mrb_nil_value();
}
static mrb_value drb_ffi_sqlite3_errcode_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_errcode': wrong number of arguments (%d for 1)", argc);
    sqlite3 *db_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    int ret_val = sqlite3_errcode(db_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_extended_errcode_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_extended_errcode': wrong number of arguments (%d for 1)", argc);
    sqlite3 *db_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    int ret_val = sqlite3_extended_errcode(db_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_errmsg_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_errmsg': wrong number of arguments (%d for 1)", argc);
    sqlite3 *_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    char *ret_val = sqlite3_errmsg(_0);
    return drb_ffi__ZTSPc_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_errmsg16_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_errmsg16': wrong number of arguments (%d for 1)", argc);
    sqlite3 *_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    void *ret_val = sqlite3_errmsg16(_0);
    return drb_ffi__ZTSPv_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_errstr_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_errstr': wrong number of arguments (%d for 1)", argc);
    int _0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    char *ret_val = sqlite3_errstr(_0);
    return drb_ffi__ZTSPc_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_error_offset_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_error_offset': wrong number of arguments (%d for 1)", argc);
    sqlite3 *db_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    int ret_val = sqlite3_error_offset(db_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_limit_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_limit': wrong number of arguments (%d for 3)", argc);
    sqlite3 *_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    int id_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    int newVal_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    int ret_val = sqlite3_limit(_0, id_1, newVal_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_prepare_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 5)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_prepare': wrong number of arguments (%d for 5)", argc);
    sqlite3 *db_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    char *zSql_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    int nByte_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    sqlite3_stmt **ppStmt_3 = drb_ffi__ZTSPP12sqlite3_stmt_FromRuby(state, args[3]);
    char **pzTail_4 = drb_ffi__ZTSPPc_FromRuby(state, args[4]);
    int ret_val = sqlite3_prepare(db_0, zSql_1, nByte_2, ppStmt_3, pzTail_4);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_prepare_v2_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 5)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_prepare_v2': wrong number of arguments (%d for 5)", argc);
    sqlite3 *db_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    char *zSql_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    int nByte_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    sqlite3_stmt **ppStmt_3 = drb_ffi__ZTSPP12sqlite3_stmt_FromRuby(state, args[3]);
    char **pzTail_4 = drb_ffi__ZTSPPc_FromRuby(state, args[4]);
    int ret_val = sqlite3_prepare_v2(db_0, zSql_1, nByte_2, ppStmt_3, pzTail_4);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_prepare_v3_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 6)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_prepare_v3': wrong number of arguments (%d for 6)", argc);
    sqlite3 *db_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    char *zSql_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    int nByte_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    unsigned int prepFlags_3 = drb_ffi__ZTSj_FromRuby(state, args[3]);
    sqlite3_stmt **ppStmt_4 = drb_ffi__ZTSPP12sqlite3_stmt_FromRuby(state, args[4]);
    char **pzTail_5 = drb_ffi__ZTSPPc_FromRuby(state, args[5]);
    int ret_val = sqlite3_prepare_v3(db_0, zSql_1, nByte_2, prepFlags_3, ppStmt_4, pzTail_5);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_prepare16_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 5)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_prepare16': wrong number of arguments (%d for 5)", argc);
    sqlite3 *db_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    void *zSql_1 = drb_ffi__ZTSPv_FromRuby(state, args[1]);
    int nByte_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    sqlite3_stmt **ppStmt_3 = drb_ffi__ZTSPP12sqlite3_stmt_FromRuby(state, args[3]);
    void **pzTail_4 = drb_ffi__ZTSPPv_FromRuby(state, args[4]);
    int ret_val = sqlite3_prepare16(db_0, zSql_1, nByte_2, ppStmt_3, pzTail_4);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_prepare16_v2_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 5)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_prepare16_v2': wrong number of arguments (%d for 5)", argc);
    sqlite3 *db_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    void *zSql_1 = drb_ffi__ZTSPv_FromRuby(state, args[1]);
    int nByte_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    sqlite3_stmt **ppStmt_3 = drb_ffi__ZTSPP12sqlite3_stmt_FromRuby(state, args[3]);
    void **pzTail_4 = drb_ffi__ZTSPPv_FromRuby(state, args[4]);
    int ret_val = sqlite3_prepare16_v2(db_0, zSql_1, nByte_2, ppStmt_3, pzTail_4);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_prepare16_v3_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 6)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_prepare16_v3': wrong number of arguments (%d for 6)", argc);
    sqlite3 *db_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    void *zSql_1 = drb_ffi__ZTSPv_FromRuby(state, args[1]);
    int nByte_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    unsigned int prepFlags_3 = drb_ffi__ZTSj_FromRuby(state, args[3]);
    sqlite3_stmt **ppStmt_4 = drb_ffi__ZTSPP12sqlite3_stmt_FromRuby(state, args[4]);
    void **pzTail_5 = drb_ffi__ZTSPPv_FromRuby(state, args[5]);
    int ret_val = sqlite3_prepare16_v3(db_0, zSql_1, nByte_2, prepFlags_3, ppStmt_4, pzTail_5);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_sql_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_sql': wrong number of arguments (%d for 1)", argc);
    sqlite3_stmt *pStmt_0 = drb_ffi__ZTSP12sqlite3_stmt_FromRuby(state, args[0]);
    char *ret_val = sqlite3_sql(pStmt_0);
    return drb_ffi__ZTSPc_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_expanded_sql_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_expanded_sql': wrong number of arguments (%d for 1)", argc);
    sqlite3_stmt *pStmt_0 = drb_ffi__ZTSP12sqlite3_stmt_FromRuby(state, args[0]);
    char *ret_val = sqlite3_expanded_sql(pStmt_0);
    return drb_ffi__ZTSPc_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_stmt_readonly_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_stmt_readonly': wrong number of arguments (%d for 1)", argc);
    sqlite3_stmt *pStmt_0 = drb_ffi__ZTSP12sqlite3_stmt_FromRuby(state, args[0]);
    int ret_val = sqlite3_stmt_readonly(pStmt_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_stmt_isexplain_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_stmt_isexplain': wrong number of arguments (%d for 1)", argc);
    sqlite3_stmt *pStmt_0 = drb_ffi__ZTSP12sqlite3_stmt_FromRuby(state, args[0]);
    int ret_val = sqlite3_stmt_isexplain(pStmt_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_stmt_busy_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_stmt_busy': wrong number of arguments (%d for 1)", argc);
    sqlite3_stmt *_0 = drb_ffi__ZTSP12sqlite3_stmt_FromRuby(state, args[0]);
    int ret_val = sqlite3_stmt_busy(_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_bind_blob_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 5)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_bind_blob': wrong number of arguments (%d for 5)", argc);
    sqlite3_stmt *_0 = drb_ffi__ZTSP12sqlite3_stmt_FromRuby(state, args[0]);
    int _1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    void *_2 = drb_ffi__ZTSPv_FromRuby(state, args[2]);
    int n_3 = drb_ffi__ZTSi_FromRuby(state, args[3]);
    void (*_4)(void *) = drb_ffi__ZTSPFvPvE_FromRuby(state, args[4]);
    int ret_val = sqlite3_bind_blob(_0, _1, _2, n_3, _4);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_bind_blob64_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 5)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_bind_blob64': wrong number of arguments (%d for 5)", argc);
    sqlite3_stmt *_0 = drb_ffi__ZTSP12sqlite3_stmt_FromRuby(state, args[0]);
    int _1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    void *_2 = drb_ffi__ZTSPv_FromRuby(state, args[2]);
    sqlite3_uint64 _3 = drb_ffi__ZTSy_FromRuby(state, args[3]);
    void (*_4)(void *) = drb_ffi__ZTSPFvPvE_FromRuby(state, args[4]);
    int ret_val = sqlite3_bind_blob64(_0, _1, _2, _3, _4);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_bind_double_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_bind_double': wrong number of arguments (%d for 3)", argc);
    sqlite3_stmt *_0 = drb_ffi__ZTSP12sqlite3_stmt_FromRuby(state, args[0]);
    int _1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    double _2 = drb_ffi__ZTSd_FromRuby(state, args[2]);
    int ret_val = sqlite3_bind_double(_0, _1, _2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_bind_int_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_bind_int': wrong number of arguments (%d for 3)", argc);
    sqlite3_stmt *_0 = drb_ffi__ZTSP12sqlite3_stmt_FromRuby(state, args[0]);
    int _1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    int _2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    int ret_val = sqlite3_bind_int(_0, _1, _2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_bind_int64_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_bind_int64': wrong number of arguments (%d for 3)", argc);
    sqlite3_stmt *_0 = drb_ffi__ZTSP12sqlite3_stmt_FromRuby(state, args[0]);
    int _1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    sqlite3_int64 _2 = drb_ffi__ZTSx_FromRuby(state, args[2]);
    int ret_val = sqlite3_bind_int64(_0, _1, _2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_bind_null_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_bind_null': wrong number of arguments (%d for 2)", argc);
    sqlite3_stmt *_0 = drb_ffi__ZTSP12sqlite3_stmt_FromRuby(state, args[0]);
    int _1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    int ret_val = sqlite3_bind_null(_0, _1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_bind_text_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 5)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_bind_text': wrong number of arguments (%d for 5)", argc);
    sqlite3_stmt *_0 = drb_ffi__ZTSP12sqlite3_stmt_FromRuby(state, args[0]);
    int _1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    char *_2 = drb_ffi__ZTSPc_FromRuby(state, args[2]);
    int _3 = drb_ffi__ZTSi_FromRuby(state, args[3]);
    void (*_4)(void *) = drb_ffi__ZTSPFvPvE_FromRuby(state, args[4]);
    int ret_val = sqlite3_bind_text(_0, _1, _2, _3, _4);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_bind_text16_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 5)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_bind_text16': wrong number of arguments (%d for 5)", argc);
    sqlite3_stmt *_0 = drb_ffi__ZTSP12sqlite3_stmt_FromRuby(state, args[0]);
    int _1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    void *_2 = drb_ffi__ZTSPv_FromRuby(state, args[2]);
    int _3 = drb_ffi__ZTSi_FromRuby(state, args[3]);
    void (*_4)(void *) = drb_ffi__ZTSPFvPvE_FromRuby(state, args[4]);
    int ret_val = sqlite3_bind_text16(_0, _1, _2, _3, _4);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_bind_text64_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 6)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_bind_text64': wrong number of arguments (%d for 6)", argc);
    sqlite3_stmt *_0 = drb_ffi__ZTSP12sqlite3_stmt_FromRuby(state, args[0]);
    int _1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    char *_2 = drb_ffi__ZTSPc_FromRuby(state, args[2]);
    sqlite3_uint64 _3 = drb_ffi__ZTSy_FromRuby(state, args[3]);
    void (*_4)(void *) = drb_ffi__ZTSPFvPvE_FromRuby(state, args[4]);
    unsigned char encoding_5 = drb_ffi__ZTSh_FromRuby(state, args[5]);
    int ret_val = sqlite3_bind_text64(_0, _1, _2, _3, _4, encoding_5);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_bind_value_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_bind_value': wrong number of arguments (%d for 3)", argc);
    sqlite3_stmt *_0 = drb_ffi__ZTSP12sqlite3_stmt_FromRuby(state, args[0]);
    int _1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    sqlite3_value *_2 = drb_ffi__ZTSP13sqlite3_value_FromRuby(state, args[2]);
    int ret_val = sqlite3_bind_value(_0, _1, _2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_bind_pointer_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 5)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_bind_pointer': wrong number of arguments (%d for 5)", argc);
    sqlite3_stmt *_0 = drb_ffi__ZTSP12sqlite3_stmt_FromRuby(state, args[0]);
    int _1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    void *_2 = drb_ffi__ZTSPv_FromRuby(state, args[2]);
    char *_3 = drb_ffi__ZTSPc_FromRuby(state, args[3]);
    void (*_4)(void *) = drb_ffi__ZTSPFvPvE_FromRuby(state, args[4]);
    int ret_val = sqlite3_bind_pointer(_0, _1, _2, _3, _4);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_bind_zeroblob_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_bind_zeroblob': wrong number of arguments (%d for 3)", argc);
    sqlite3_stmt *_0 = drb_ffi__ZTSP12sqlite3_stmt_FromRuby(state, args[0]);
    int _1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    int n_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    int ret_val = sqlite3_bind_zeroblob(_0, _1, n_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_bind_zeroblob64_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_bind_zeroblob64': wrong number of arguments (%d for 3)", argc);
    sqlite3_stmt *_0 = drb_ffi__ZTSP12sqlite3_stmt_FromRuby(state, args[0]);
    int _1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    sqlite3_uint64 _2 = drb_ffi__ZTSy_FromRuby(state, args[2]);
    int ret_val = sqlite3_bind_zeroblob64(_0, _1, _2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_bind_parameter_count_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_bind_parameter_count': wrong number of arguments (%d for 1)", argc);
    sqlite3_stmt *_0 = drb_ffi__ZTSP12sqlite3_stmt_FromRuby(state, args[0]);
    int ret_val = sqlite3_bind_parameter_count(_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_bind_parameter_name_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_bind_parameter_name': wrong number of arguments (%d for 2)", argc);
    sqlite3_stmt *_0 = drb_ffi__ZTSP12sqlite3_stmt_FromRuby(state, args[0]);
    int _1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    char *ret_val = sqlite3_bind_parameter_name(_0, _1);
    return drb_ffi__ZTSPc_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_bind_parameter_index_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_bind_parameter_index': wrong number of arguments (%d for 2)", argc);
    sqlite3_stmt *_0 = drb_ffi__ZTSP12sqlite3_stmt_FromRuby(state, args[0]);
    char *zName_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    int ret_val = sqlite3_bind_parameter_index(_0, zName_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_clear_bindings_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_clear_bindings': wrong number of arguments (%d for 1)", argc);
    sqlite3_stmt *_0 = drb_ffi__ZTSP12sqlite3_stmt_FromRuby(state, args[0]);
    int ret_val = sqlite3_clear_bindings(_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_column_count_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_column_count': wrong number of arguments (%d for 1)", argc);
    sqlite3_stmt *pStmt_0 = drb_ffi__ZTSP12sqlite3_stmt_FromRuby(state, args[0]);
    int ret_val = sqlite3_column_count(pStmt_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_column_name_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_column_name': wrong number of arguments (%d for 2)", argc);
    sqlite3_stmt *_0 = drb_ffi__ZTSP12sqlite3_stmt_FromRuby(state, args[0]);
    int N_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    char *ret_val = sqlite3_column_name(_0, N_1);
    return drb_ffi__ZTSPc_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_column_name16_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_column_name16': wrong number of arguments (%d for 2)", argc);
    sqlite3_stmt *_0 = drb_ffi__ZTSP12sqlite3_stmt_FromRuby(state, args[0]);
    int N_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    void *ret_val = sqlite3_column_name16(_0, N_1);
    return drb_ffi__ZTSPv_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_column_database_name_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_column_database_name': wrong number of arguments (%d for 2)", argc);
    sqlite3_stmt *_0 = drb_ffi__ZTSP12sqlite3_stmt_FromRuby(state, args[0]);
    int _1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    char *ret_val = sqlite3_column_database_name(_0, _1);
    return drb_ffi__ZTSPc_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_column_database_name16_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_column_database_name16': wrong number of arguments (%d for 2)", argc);
    sqlite3_stmt *_0 = drb_ffi__ZTSP12sqlite3_stmt_FromRuby(state, args[0]);
    int _1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    void *ret_val = sqlite3_column_database_name16(_0, _1);
    return drb_ffi__ZTSPv_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_column_table_name_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_column_table_name': wrong number of arguments (%d for 2)", argc);
    sqlite3_stmt *_0 = drb_ffi__ZTSP12sqlite3_stmt_FromRuby(state, args[0]);
    int _1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    char *ret_val = sqlite3_column_table_name(_0, _1);
    return drb_ffi__ZTSPc_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_column_table_name16_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_column_table_name16': wrong number of arguments (%d for 2)", argc);
    sqlite3_stmt *_0 = drb_ffi__ZTSP12sqlite3_stmt_FromRuby(state, args[0]);
    int _1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    void *ret_val = sqlite3_column_table_name16(_0, _1);
    return drb_ffi__ZTSPv_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_column_origin_name_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_column_origin_name': wrong number of arguments (%d for 2)", argc);
    sqlite3_stmt *_0 = drb_ffi__ZTSP12sqlite3_stmt_FromRuby(state, args[0]);
    int _1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    char *ret_val = sqlite3_column_origin_name(_0, _1);
    return drb_ffi__ZTSPc_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_column_origin_name16_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_column_origin_name16': wrong number of arguments (%d for 2)", argc);
    sqlite3_stmt *_0 = drb_ffi__ZTSP12sqlite3_stmt_FromRuby(state, args[0]);
    int _1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    void *ret_val = sqlite3_column_origin_name16(_0, _1);
    return drb_ffi__ZTSPv_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_column_decltype_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_column_decltype': wrong number of arguments (%d for 2)", argc);
    sqlite3_stmt *_0 = drb_ffi__ZTSP12sqlite3_stmt_FromRuby(state, args[0]);
    int _1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    char *ret_val = sqlite3_column_decltype(_0, _1);
    return drb_ffi__ZTSPc_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_column_decltype16_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_column_decltype16': wrong number of arguments (%d for 2)", argc);
    sqlite3_stmt *_0 = drb_ffi__ZTSP12sqlite3_stmt_FromRuby(state, args[0]);
    int _1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    void *ret_val = sqlite3_column_decltype16(_0, _1);
    return drb_ffi__ZTSPv_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_step_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_step': wrong number of arguments (%d for 1)", argc);
    sqlite3_stmt *_0 = drb_ffi__ZTSP12sqlite3_stmt_FromRuby(state, args[0]);
    int ret_val = sqlite3_step(_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_data_count_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_data_count': wrong number of arguments (%d for 1)", argc);
    sqlite3_stmt *pStmt_0 = drb_ffi__ZTSP12sqlite3_stmt_FromRuby(state, args[0]);
    int ret_val = sqlite3_data_count(pStmt_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_column_blob_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_column_blob': wrong number of arguments (%d for 2)", argc);
    sqlite3_stmt *_0 = drb_ffi__ZTSP12sqlite3_stmt_FromRuby(state, args[0]);
    int iCol_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    void *ret_val = sqlite3_column_blob(_0, iCol_1);
    return drb_ffi__ZTSPv_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_column_double_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_column_double': wrong number of arguments (%d for 2)", argc);
    sqlite3_stmt *_0 = drb_ffi__ZTSP12sqlite3_stmt_FromRuby(state, args[0]);
    int iCol_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    double ret_val = sqlite3_column_double(_0, iCol_1);
    return drb_ffi__ZTSd_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_column_int_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_column_int': wrong number of arguments (%d for 2)", argc);
    sqlite3_stmt *_0 = drb_ffi__ZTSP12sqlite3_stmt_FromRuby(state, args[0]);
    int iCol_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    int ret_val = sqlite3_column_int(_0, iCol_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_column_int64_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_column_int64': wrong number of arguments (%d for 2)", argc);
    sqlite3_stmt *_0 = drb_ffi__ZTSP12sqlite3_stmt_FromRuby(state, args[0]);
    int iCol_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    sqlite3_int64 ret_val = sqlite3_column_int64(_0, iCol_1);
    return drb_ffi__ZTSx_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_column_text_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_column_text': wrong number of arguments (%d for 2)", argc);
    sqlite3_stmt *_0 = drb_ffi__ZTSP12sqlite3_stmt_FromRuby(state, args[0]);
    int iCol_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    unsigned char *ret_val = sqlite3_column_text(_0, iCol_1);
    return drb_ffi__ZTSPh_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_column_text16_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_column_text16': wrong number of arguments (%d for 2)", argc);
    sqlite3_stmt *_0 = drb_ffi__ZTSP12sqlite3_stmt_FromRuby(state, args[0]);
    int iCol_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    void *ret_val = sqlite3_column_text16(_0, iCol_1);
    return drb_ffi__ZTSPv_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_column_value_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_column_value': wrong number of arguments (%d for 2)", argc);
    sqlite3_stmt *_0 = drb_ffi__ZTSP12sqlite3_stmt_FromRuby(state, args[0]);
    int iCol_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    sqlite3_value *ret_val = sqlite3_column_value(_0, iCol_1);
    return drb_ffi__ZTSP13sqlite3_value_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_column_bytes_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_column_bytes': wrong number of arguments (%d for 2)", argc);
    sqlite3_stmt *_0 = drb_ffi__ZTSP12sqlite3_stmt_FromRuby(state, args[0]);
    int iCol_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    int ret_val = sqlite3_column_bytes(_0, iCol_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_column_bytes16_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_column_bytes16': wrong number of arguments (%d for 2)", argc);
    sqlite3_stmt *_0 = drb_ffi__ZTSP12sqlite3_stmt_FromRuby(state, args[0]);
    int iCol_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    int ret_val = sqlite3_column_bytes16(_0, iCol_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_column_type_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_column_type': wrong number of arguments (%d for 2)", argc);
    sqlite3_stmt *_0 = drb_ffi__ZTSP12sqlite3_stmt_FromRuby(state, args[0]);
    int iCol_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    int ret_val = sqlite3_column_type(_0, iCol_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_finalize_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_finalize': wrong number of arguments (%d for 1)", argc);
    sqlite3_stmt *pStmt_0 = drb_ffi__ZTSP12sqlite3_stmt_FromRuby(state, args[0]);
    int ret_val = sqlite3_finalize(pStmt_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_reset_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_reset': wrong number of arguments (%d for 1)", argc);
    sqlite3_stmt *pStmt_0 = drb_ffi__ZTSP12sqlite3_stmt_FromRuby(state, args[0]);
    int ret_val = sqlite3_reset(pStmt_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_create_function_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 8)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_create_function': wrong number of arguments (%d for 8)", argc);
    sqlite3 *db_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    char *zFunctionName_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    int nArg_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    int eTextRep_3 = drb_ffi__ZTSi_FromRuby(state, args[3]);
    void *pApp_4 = drb_ffi__ZTSPv_FromRuby(state, args[4]);
    void (*xFunc_5)(sqlite3_context *, int, sqlite3_value **) = drb_ffi__ZTSPFvP15sqlite3_contextiPP13sqlite3_valueE_FromRuby(state, args[5]);
    void (*xStep_6)(sqlite3_context *, int, sqlite3_value **) = drb_ffi__ZTSPFvP15sqlite3_contextiPP13sqlite3_valueE_FromRuby(state, args[6]);
    void (*xFinal_7)(sqlite3_context *) = drb_ffi__ZTSPFvP15sqlite3_contextE_FromRuby(state, args[7]);
    int ret_val = sqlite3_create_function(db_0, zFunctionName_1, nArg_2, eTextRep_3, pApp_4, xFunc_5, xStep_6, xFinal_7);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_create_function16_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 8)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_create_function16': wrong number of arguments (%d for 8)", argc);
    sqlite3 *db_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    void *zFunctionName_1 = drb_ffi__ZTSPv_FromRuby(state, args[1]);
    int nArg_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    int eTextRep_3 = drb_ffi__ZTSi_FromRuby(state, args[3]);
    void *pApp_4 = drb_ffi__ZTSPv_FromRuby(state, args[4]);
    void (*xFunc_5)(sqlite3_context *, int, sqlite3_value **) = drb_ffi__ZTSPFvP15sqlite3_contextiPP13sqlite3_valueE_FromRuby(state, args[5]);
    void (*xStep_6)(sqlite3_context *, int, sqlite3_value **) = drb_ffi__ZTSPFvP15sqlite3_contextiPP13sqlite3_valueE_FromRuby(state, args[6]);
    void (*xFinal_7)(sqlite3_context *) = drb_ffi__ZTSPFvP15sqlite3_contextE_FromRuby(state, args[7]);
    int ret_val = sqlite3_create_function16(db_0, zFunctionName_1, nArg_2, eTextRep_3, pApp_4, xFunc_5, xStep_6, xFinal_7);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_create_function_v2_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 9)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_create_function_v2': wrong number of arguments (%d for 9)", argc);
    sqlite3 *db_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    char *zFunctionName_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    int nArg_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    int eTextRep_3 = drb_ffi__ZTSi_FromRuby(state, args[3]);
    void *pApp_4 = drb_ffi__ZTSPv_FromRuby(state, args[4]);
    void (*xFunc_5)(sqlite3_context *, int, sqlite3_value **) = drb_ffi__ZTSPFvP15sqlite3_contextiPP13sqlite3_valueE_FromRuby(state, args[5]);
    void (*xStep_6)(sqlite3_context *, int, sqlite3_value **) = drb_ffi__ZTSPFvP15sqlite3_contextiPP13sqlite3_valueE_FromRuby(state, args[6]);
    void (*xFinal_7)(sqlite3_context *) = drb_ffi__ZTSPFvP15sqlite3_contextE_FromRuby(state, args[7]);
    void (*xDestroy_8)(void *) = drb_ffi__ZTSPFvPvE_FromRuby(state, args[8]);
    int ret_val = sqlite3_create_function_v2(db_0, zFunctionName_1, nArg_2, eTextRep_3, pApp_4, xFunc_5, xStep_6, xFinal_7, xDestroy_8);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_create_window_function_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 10)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_create_window_function': wrong number of arguments (%d for 10)", argc);
    sqlite3 *db_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    char *zFunctionName_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    int nArg_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    int eTextRep_3 = drb_ffi__ZTSi_FromRuby(state, args[3]);
    void *pApp_4 = drb_ffi__ZTSPv_FromRuby(state, args[4]);
    void (*xStep_5)(sqlite3_context *, int, sqlite3_value **) = drb_ffi__ZTSPFvP15sqlite3_contextiPP13sqlite3_valueE_FromRuby(state, args[5]);
    void (*xFinal_6)(sqlite3_context *) = drb_ffi__ZTSPFvP15sqlite3_contextE_FromRuby(state, args[6]);
    void (*xValue_7)(sqlite3_context *) = drb_ffi__ZTSPFvP15sqlite3_contextE_FromRuby(state, args[7]);
    void (*xInverse_8)(sqlite3_context *, int, sqlite3_value **) = drb_ffi__ZTSPFvP15sqlite3_contextiPP13sqlite3_valueE_FromRuby(state, args[8]);
    void (*xDestroy_9)(void *) = drb_ffi__ZTSPFvPvE_FromRuby(state, args[9]);
    int ret_val = sqlite3_create_window_function(db_0, zFunctionName_1, nArg_2, eTextRep_3, pApp_4, xStep_5, xFinal_6, xValue_7, xInverse_8, xDestroy_9);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_aggregate_count_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_aggregate_count': wrong number of arguments (%d for 1)", argc);
    sqlite3_context *_0 = drb_ffi__ZTSP15sqlite3_context_FromRuby(state, args[0]);
    int ret_val = sqlite3_aggregate_count(_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_expired_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_expired': wrong number of arguments (%d for 1)", argc);
    sqlite3_stmt *_0 = drb_ffi__ZTSP12sqlite3_stmt_FromRuby(state, args[0]);
    int ret_val = sqlite3_expired(_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_transfer_bindings_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_transfer_bindings': wrong number of arguments (%d for 2)", argc);
    sqlite3_stmt *_0 = drb_ffi__ZTSP12sqlite3_stmt_FromRuby(state, args[0]);
    sqlite3_stmt *_1 = drb_ffi__ZTSP12sqlite3_stmt_FromRuby(state, args[1]);
    int ret_val = sqlite3_transfer_bindings(_0, _1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_global_recover_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 0)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_global_recover': wrong number of arguments (%d for 0)", argc);
    int ret_val = sqlite3_global_recover();
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_thread_cleanup_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 0)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_thread_cleanup': wrong number of arguments (%d for 0)", argc);
    sqlite3_thread_cleanup();
    return mrb_nil_value();
}
static mrb_value drb_ffi_sqlite3_memory_alarm_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_memory_alarm': wrong number of arguments (%d for 3)", argc);
    void (*_0)(void *, sqlite3_int64, int) = drb_ffi__ZTSPFvPvxiE_FromRuby(state, args[0]);
    void *_1 = drb_ffi__ZTSPv_FromRuby(state, args[1]);
    sqlite3_int64 _2 = drb_ffi__ZTSx_FromRuby(state, args[2]);
    int ret_val = sqlite3_memory_alarm(_0, _1, _2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_value_blob_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_value_blob': wrong number of arguments (%d for 1)", argc);
    sqlite3_value *_0 = drb_ffi__ZTSP13sqlite3_value_FromRuby(state, args[0]);
    void *ret_val = sqlite3_value_blob(_0);
    return drb_ffi__ZTSPv_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_value_double_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_value_double': wrong number of arguments (%d for 1)", argc);
    sqlite3_value *_0 = drb_ffi__ZTSP13sqlite3_value_FromRuby(state, args[0]);
    double ret_val = sqlite3_value_double(_0);
    return drb_ffi__ZTSd_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_value_int_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_value_int': wrong number of arguments (%d for 1)", argc);
    sqlite3_value *_0 = drb_ffi__ZTSP13sqlite3_value_FromRuby(state, args[0]);
    int ret_val = sqlite3_value_int(_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_value_int64_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_value_int64': wrong number of arguments (%d for 1)", argc);
    sqlite3_value *_0 = drb_ffi__ZTSP13sqlite3_value_FromRuby(state, args[0]);
    sqlite3_int64 ret_val = sqlite3_value_int64(_0);
    return drb_ffi__ZTSx_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_value_pointer_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_value_pointer': wrong number of arguments (%d for 2)", argc);
    sqlite3_value *_0 = drb_ffi__ZTSP13sqlite3_value_FromRuby(state, args[0]);
    char *_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    void *ret_val = sqlite3_value_pointer(_0, _1);
    return drb_ffi__ZTSPv_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_value_text_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_value_text': wrong number of arguments (%d for 1)", argc);
    sqlite3_value *_0 = drb_ffi__ZTSP13sqlite3_value_FromRuby(state, args[0]);
    unsigned char *ret_val = sqlite3_value_text(_0);
    return drb_ffi__ZTSPh_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_value_text16_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_value_text16': wrong number of arguments (%d for 1)", argc);
    sqlite3_value *_0 = drb_ffi__ZTSP13sqlite3_value_FromRuby(state, args[0]);
    void *ret_val = sqlite3_value_text16(_0);
    return drb_ffi__ZTSPv_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_value_text16le_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_value_text16le': wrong number of arguments (%d for 1)", argc);
    sqlite3_value *_0 = drb_ffi__ZTSP13sqlite3_value_FromRuby(state, args[0]);
    void *ret_val = sqlite3_value_text16le(_0);
    return drb_ffi__ZTSPv_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_value_text16be_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_value_text16be': wrong number of arguments (%d for 1)", argc);
    sqlite3_value *_0 = drb_ffi__ZTSP13sqlite3_value_FromRuby(state, args[0]);
    void *ret_val = sqlite3_value_text16be(_0);
    return drb_ffi__ZTSPv_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_value_bytes_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_value_bytes': wrong number of arguments (%d for 1)", argc);
    sqlite3_value *_0 = drb_ffi__ZTSP13sqlite3_value_FromRuby(state, args[0]);
    int ret_val = sqlite3_value_bytes(_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_value_bytes16_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_value_bytes16': wrong number of arguments (%d for 1)", argc);
    sqlite3_value *_0 = drb_ffi__ZTSP13sqlite3_value_FromRuby(state, args[0]);
    int ret_val = sqlite3_value_bytes16(_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_value_type_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_value_type': wrong number of arguments (%d for 1)", argc);
    sqlite3_value *_0 = drb_ffi__ZTSP13sqlite3_value_FromRuby(state, args[0]);
    int ret_val = sqlite3_value_type(_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_value_numeric_type_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_value_numeric_type': wrong number of arguments (%d for 1)", argc);
    sqlite3_value *_0 = drb_ffi__ZTSP13sqlite3_value_FromRuby(state, args[0]);
    int ret_val = sqlite3_value_numeric_type(_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_value_nochange_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_value_nochange': wrong number of arguments (%d for 1)", argc);
    sqlite3_value *_0 = drb_ffi__ZTSP13sqlite3_value_FromRuby(state, args[0]);
    int ret_val = sqlite3_value_nochange(_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_value_frombind_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_value_frombind': wrong number of arguments (%d for 1)", argc);
    sqlite3_value *_0 = drb_ffi__ZTSP13sqlite3_value_FromRuby(state, args[0]);
    int ret_val = sqlite3_value_frombind(_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_value_subtype_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_value_subtype': wrong number of arguments (%d for 1)", argc);
    sqlite3_value *_0 = drb_ffi__ZTSP13sqlite3_value_FromRuby(state, args[0]);
    unsigned int ret_val = sqlite3_value_subtype(_0);
    return drb_ffi__ZTSj_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_value_dup_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_value_dup': wrong number of arguments (%d for 1)", argc);
    sqlite3_value *_0 = drb_ffi__ZTSP13sqlite3_value_FromRuby(state, args[0]);
    sqlite3_value *ret_val = sqlite3_value_dup(_0);
    return drb_ffi__ZTSP13sqlite3_value_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_value_free_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_value_free': wrong number of arguments (%d for 1)", argc);
    sqlite3_value *_0 = drb_ffi__ZTSP13sqlite3_value_FromRuby(state, args[0]);
    sqlite3_value_free(_0);
    return mrb_nil_value();
}
static mrb_value drb_ffi_sqlite3_aggregate_context_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_aggregate_context': wrong number of arguments (%d for 2)", argc);
    sqlite3_context *_0 = drb_ffi__ZTSP15sqlite3_context_FromRuby(state, args[0]);
    int nBytes_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    void *ret_val = sqlite3_aggregate_context(_0, nBytes_1);
    return drb_ffi__ZTSPv_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_user_data_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_user_data': wrong number of arguments (%d for 1)", argc);
    sqlite3_context *_0 = drb_ffi__ZTSP15sqlite3_context_FromRuby(state, args[0]);
    void *ret_val = sqlite3_user_data(_0);
    return drb_ffi__ZTSPv_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_context_db_handle_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_context_db_handle': wrong number of arguments (%d for 1)", argc);
    sqlite3_context *_0 = drb_ffi__ZTSP15sqlite3_context_FromRuby(state, args[0]);
    sqlite3 *ret_val = sqlite3_context_db_handle(_0);
    return drb_ffi__ZTSP7sqlite3_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_get_auxdata_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_get_auxdata': wrong number of arguments (%d for 2)", argc);
    sqlite3_context *_0 = drb_ffi__ZTSP15sqlite3_context_FromRuby(state, args[0]);
    int N_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    void *ret_val = sqlite3_get_auxdata(_0, N_1);
    return drb_ffi__ZTSPv_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_set_auxdata_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 4)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_set_auxdata': wrong number of arguments (%d for 4)", argc);
    sqlite3_context *_0 = drb_ffi__ZTSP15sqlite3_context_FromRuby(state, args[0]);
    int N_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    void *_2 = drb_ffi__ZTSPv_FromRuby(state, args[2]);
    void (*_3)(void *) = drb_ffi__ZTSPFvPvE_FromRuby(state, args[3]);
    sqlite3_set_auxdata(_0, N_1, _2, _3);
    return mrb_nil_value();
}
static mrb_value drb_ffi_sqlite3_result_blob_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 4)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_result_blob': wrong number of arguments (%d for 4)", argc);
    sqlite3_context *_0 = drb_ffi__ZTSP15sqlite3_context_FromRuby(state, args[0]);
    void *_1 = drb_ffi__ZTSPv_FromRuby(state, args[1]);
    int _2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    void (*_3)(void *) = drb_ffi__ZTSPFvPvE_FromRuby(state, args[3]);
    sqlite3_result_blob(_0, _1, _2, _3);
    return mrb_nil_value();
}
static mrb_value drb_ffi_sqlite3_result_blob64_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 4)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_result_blob64': wrong number of arguments (%d for 4)", argc);
    sqlite3_context *_0 = drb_ffi__ZTSP15sqlite3_context_FromRuby(state, args[0]);
    void *_1 = drb_ffi__ZTSPv_FromRuby(state, args[1]);
    sqlite3_uint64 _2 = drb_ffi__ZTSy_FromRuby(state, args[2]);
    void (*_3)(void *) = drb_ffi__ZTSPFvPvE_FromRuby(state, args[3]);
    sqlite3_result_blob64(_0, _1, _2, _3);
    return mrb_nil_value();
}
static mrb_value drb_ffi_sqlite3_result_double_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_result_double': wrong number of arguments (%d for 2)", argc);
    sqlite3_context *_0 = drb_ffi__ZTSP15sqlite3_context_FromRuby(state, args[0]);
    double _1 = drb_ffi__ZTSd_FromRuby(state, args[1]);
    sqlite3_result_double(_0, _1);
    return mrb_nil_value();
}
static mrb_value drb_ffi_sqlite3_result_error_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_result_error': wrong number of arguments (%d for 3)", argc);
    sqlite3_context *_0 = drb_ffi__ZTSP15sqlite3_context_FromRuby(state, args[0]);
    char *_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    int _2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    sqlite3_result_error(_0, _1, _2);
    return mrb_nil_value();
}
static mrb_value drb_ffi_sqlite3_result_error16_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_result_error16': wrong number of arguments (%d for 3)", argc);
    sqlite3_context *_0 = drb_ffi__ZTSP15sqlite3_context_FromRuby(state, args[0]);
    void *_1 = drb_ffi__ZTSPv_FromRuby(state, args[1]);
    int _2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    sqlite3_result_error16(_0, _1, _2);
    return mrb_nil_value();
}
static mrb_value drb_ffi_sqlite3_result_error_toobig_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_result_error_toobig': wrong number of arguments (%d for 1)", argc);
    sqlite3_context *_0 = drb_ffi__ZTSP15sqlite3_context_FromRuby(state, args[0]);
    sqlite3_result_error_toobig(_0);
    return mrb_nil_value();
}
static mrb_value drb_ffi_sqlite3_result_error_nomem_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_result_error_nomem': wrong number of arguments (%d for 1)", argc);
    sqlite3_context *_0 = drb_ffi__ZTSP15sqlite3_context_FromRuby(state, args[0]);
    sqlite3_result_error_nomem(_0);
    return mrb_nil_value();
}
static mrb_value drb_ffi_sqlite3_result_error_code_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_result_error_code': wrong number of arguments (%d for 2)", argc);
    sqlite3_context *_0 = drb_ffi__ZTSP15sqlite3_context_FromRuby(state, args[0]);
    int _1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    sqlite3_result_error_code(_0, _1);
    return mrb_nil_value();
}
static mrb_value drb_ffi_sqlite3_result_int_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_result_int': wrong number of arguments (%d for 2)", argc);
    sqlite3_context *_0 = drb_ffi__ZTSP15sqlite3_context_FromRuby(state, args[0]);
    int _1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    sqlite3_result_int(_0, _1);
    return mrb_nil_value();
}
static mrb_value drb_ffi_sqlite3_result_int64_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_result_int64': wrong number of arguments (%d for 2)", argc);
    sqlite3_context *_0 = drb_ffi__ZTSP15sqlite3_context_FromRuby(state, args[0]);
    sqlite3_int64 _1 = drb_ffi__ZTSx_FromRuby(state, args[1]);
    sqlite3_result_int64(_0, _1);
    return mrb_nil_value();
}
static mrb_value drb_ffi_sqlite3_result_null_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_result_null': wrong number of arguments (%d for 1)", argc);
    sqlite3_context *_0 = drb_ffi__ZTSP15sqlite3_context_FromRuby(state, args[0]);
    sqlite3_result_null(_0);
    return mrb_nil_value();
}
static mrb_value drb_ffi_sqlite3_result_text_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 4)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_result_text': wrong number of arguments (%d for 4)", argc);
    sqlite3_context *_0 = drb_ffi__ZTSP15sqlite3_context_FromRuby(state, args[0]);
    char *_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    int _2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    void (*_3)(void *) = drb_ffi__ZTSPFvPvE_FromRuby(state, args[3]);
    sqlite3_result_text(_0, _1, _2, _3);
    return mrb_nil_value();
}
static mrb_value drb_ffi_sqlite3_result_text64_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 5)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_result_text64': wrong number of arguments (%d for 5)", argc);
    sqlite3_context *_0 = drb_ffi__ZTSP15sqlite3_context_FromRuby(state, args[0]);
    char *_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    sqlite3_uint64 _2 = drb_ffi__ZTSy_FromRuby(state, args[2]);
    void (*_3)(void *) = drb_ffi__ZTSPFvPvE_FromRuby(state, args[3]);
    unsigned char encoding_4 = drb_ffi__ZTSh_FromRuby(state, args[4]);
    sqlite3_result_text64(_0, _1, _2, _3, encoding_4);
    return mrb_nil_value();
}
static mrb_value drb_ffi_sqlite3_result_text16_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 4)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_result_text16': wrong number of arguments (%d for 4)", argc);
    sqlite3_context *_0 = drb_ffi__ZTSP15sqlite3_context_FromRuby(state, args[0]);
    void *_1 = drb_ffi__ZTSPv_FromRuby(state, args[1]);
    int _2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    void (*_3)(void *) = drb_ffi__ZTSPFvPvE_FromRuby(state, args[3]);
    sqlite3_result_text16(_0, _1, _2, _3);
    return mrb_nil_value();
}
static mrb_value drb_ffi_sqlite3_result_text16le_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 4)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_result_text16le': wrong number of arguments (%d for 4)", argc);
    sqlite3_context *_0 = drb_ffi__ZTSP15sqlite3_context_FromRuby(state, args[0]);
    void *_1 = drb_ffi__ZTSPv_FromRuby(state, args[1]);
    int _2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    void (*_3)(void *) = drb_ffi__ZTSPFvPvE_FromRuby(state, args[3]);
    sqlite3_result_text16le(_0, _1, _2, _3);
    return mrb_nil_value();
}
static mrb_value drb_ffi_sqlite3_result_text16be_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 4)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_result_text16be': wrong number of arguments (%d for 4)", argc);
    sqlite3_context *_0 = drb_ffi__ZTSP15sqlite3_context_FromRuby(state, args[0]);
    void *_1 = drb_ffi__ZTSPv_FromRuby(state, args[1]);
    int _2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    void (*_3)(void *) = drb_ffi__ZTSPFvPvE_FromRuby(state, args[3]);
    sqlite3_result_text16be(_0, _1, _2, _3);
    return mrb_nil_value();
}
static mrb_value drb_ffi_sqlite3_result_value_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_result_value': wrong number of arguments (%d for 2)", argc);
    sqlite3_context *_0 = drb_ffi__ZTSP15sqlite3_context_FromRuby(state, args[0]);
    sqlite3_value *_1 = drb_ffi__ZTSP13sqlite3_value_FromRuby(state, args[1]);
    sqlite3_result_value(_0, _1);
    return mrb_nil_value();
}
static mrb_value drb_ffi_sqlite3_result_pointer_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 4)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_result_pointer': wrong number of arguments (%d for 4)", argc);
    sqlite3_context *_0 = drb_ffi__ZTSP15sqlite3_context_FromRuby(state, args[0]);
    void *_1 = drb_ffi__ZTSPv_FromRuby(state, args[1]);
    char *_2 = drb_ffi__ZTSPc_FromRuby(state, args[2]);
    void (*_3)(void *) = drb_ffi__ZTSPFvPvE_FromRuby(state, args[3]);
    sqlite3_result_pointer(_0, _1, _2, _3);
    return mrb_nil_value();
}
static mrb_value drb_ffi_sqlite3_result_zeroblob_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_result_zeroblob': wrong number of arguments (%d for 2)", argc);
    sqlite3_context *_0 = drb_ffi__ZTSP15sqlite3_context_FromRuby(state, args[0]);
    int n_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    sqlite3_result_zeroblob(_0, n_1);
    return mrb_nil_value();
}
static mrb_value drb_ffi_sqlite3_result_zeroblob64_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_result_zeroblob64': wrong number of arguments (%d for 2)", argc);
    sqlite3_context *_0 = drb_ffi__ZTSP15sqlite3_context_FromRuby(state, args[0]);
    sqlite3_uint64 n_1 = drb_ffi__ZTSy_FromRuby(state, args[1]);
    int ret_val = sqlite3_result_zeroblob64(_0, n_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_result_subtype_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_result_subtype': wrong number of arguments (%d for 2)", argc);
    sqlite3_context *_0 = drb_ffi__ZTSP15sqlite3_context_FromRuby(state, args[0]);
    unsigned int _1 = drb_ffi__ZTSj_FromRuby(state, args[1]);
    sqlite3_result_subtype(_0, _1);
    return mrb_nil_value();
}
static mrb_value drb_ffi_sqlite3_create_collation_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 5)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_create_collation': wrong number of arguments (%d for 5)", argc);
    sqlite3 *_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    char *zName_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    int eTextRep_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    void *pArg_3 = drb_ffi__ZTSPv_FromRuby(state, args[3]);
    int (*xCompare_4)(void *, int, const void *, int, const void *) = drb_ffi__ZTSPFiPviPKviS1_E_FromRuby(state, args[4]);
    int ret_val = sqlite3_create_collation(_0, zName_1, eTextRep_2, pArg_3, xCompare_4);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_create_collation_v2_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 6)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_create_collation_v2': wrong number of arguments (%d for 6)", argc);
    sqlite3 *_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    char *zName_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    int eTextRep_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    void *pArg_3 = drb_ffi__ZTSPv_FromRuby(state, args[3]);
    int (*xCompare_4)(void *, int, const void *, int, const void *) = drb_ffi__ZTSPFiPviPKviS1_E_FromRuby(state, args[4]);
    void (*xDestroy_5)(void *) = drb_ffi__ZTSPFvPvE_FromRuby(state, args[5]);
    int ret_val = sqlite3_create_collation_v2(_0, zName_1, eTextRep_2, pArg_3, xCompare_4, xDestroy_5);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_create_collation16_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 5)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_create_collation16': wrong number of arguments (%d for 5)", argc);
    sqlite3 *_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    void *zName_1 = drb_ffi__ZTSPv_FromRuby(state, args[1]);
    int eTextRep_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    void *pArg_3 = drb_ffi__ZTSPv_FromRuby(state, args[3]);
    int (*xCompare_4)(void *, int, const void *, int, const void *) = drb_ffi__ZTSPFiPviPKviS1_E_FromRuby(state, args[4]);
    int ret_val = sqlite3_create_collation16(_0, zName_1, eTextRep_2, pArg_3, xCompare_4);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_collation_needed_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_collation_needed': wrong number of arguments (%d for 3)", argc);
    sqlite3 *_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    void *_1 = drb_ffi__ZTSPv_FromRuby(state, args[1]);
    void (*_2)(void *, sqlite3 *, int, const char *) = drb_ffi__ZTSPFvPvP7sqlite3iPKcE_FromRuby(state, args[2]);
    int ret_val = sqlite3_collation_needed(_0, _1, _2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_collation_needed16_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_collation_needed16': wrong number of arguments (%d for 3)", argc);
    sqlite3 *_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    void *_1 = drb_ffi__ZTSPv_FromRuby(state, args[1]);
    void (*_2)(void *, sqlite3 *, int, const void *) = drb_ffi__ZTSPFvPvP7sqlite3iPKvE_FromRuby(state, args[2]);
    int ret_val = sqlite3_collation_needed16(_0, _1, _2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_sleep_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_sleep': wrong number of arguments (%d for 1)", argc);
    int _0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    int ret_val = sqlite3_sleep(_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_win32_set_directory_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_win32_set_directory': wrong number of arguments (%d for 2)", argc);
    unsigned long type_0 = drb_ffi__ZTSm_FromRuby(state, args[0]);
    void *zValue_1 = drb_ffi__ZTSPv_FromRuby(state, args[1]);
    int ret_val = sqlite3_win32_set_directory(type_0, zValue_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_win32_set_directory8_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_win32_set_directory8': wrong number of arguments (%d for 2)", argc);
    unsigned long type_0 = drb_ffi__ZTSm_FromRuby(state, args[0]);
    char *zValue_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    int ret_val = sqlite3_win32_set_directory8(type_0, zValue_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_win32_set_directory16_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_win32_set_directory16': wrong number of arguments (%d for 2)", argc);
    unsigned long type_0 = drb_ffi__ZTSm_FromRuby(state, args[0]);
    void *zValue_1 = drb_ffi__ZTSPv_FromRuby(state, args[1]);
    int ret_val = sqlite3_win32_set_directory16(type_0, zValue_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_get_autocommit_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_get_autocommit': wrong number of arguments (%d for 1)", argc);
    sqlite3 *_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    int ret_val = sqlite3_get_autocommit(_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_db_handle_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_db_handle': wrong number of arguments (%d for 1)", argc);
    sqlite3_stmt *_0 = drb_ffi__ZTSP12sqlite3_stmt_FromRuby(state, args[0]);
    sqlite3 *ret_val = sqlite3_db_handle(_0);
    return drb_ffi__ZTSP7sqlite3_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_db_filename_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_db_filename': wrong number of arguments (%d for 2)", argc);
    sqlite3 *db_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    char *zDbName_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    char *ret_val = sqlite3_db_filename(db_0, zDbName_1);
    return drb_ffi__ZTSPc_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_db_readonly_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_db_readonly': wrong number of arguments (%d for 2)", argc);
    sqlite3 *db_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    char *zDbName_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    int ret_val = sqlite3_db_readonly(db_0, zDbName_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_txn_state_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_txn_state': wrong number of arguments (%d for 2)", argc);
    sqlite3 *_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    char *zSchema_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    int ret_val = sqlite3_txn_state(_0, zSchema_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_next_stmt_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_next_stmt': wrong number of arguments (%d for 2)", argc);
    sqlite3 *pDb_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    sqlite3_stmt *pStmt_1 = drb_ffi__ZTSP12sqlite3_stmt_FromRuby(state, args[1]);
    sqlite3_stmt *ret_val = sqlite3_next_stmt(pDb_0, pStmt_1);
    return drb_ffi__ZTSP12sqlite3_stmt_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_commit_hook_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_commit_hook': wrong number of arguments (%d for 3)", argc);
    sqlite3 *_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    int (*_1)(void *) = drb_ffi__ZTSPFiPvE_FromRuby(state, args[1]);
    void *_2 = drb_ffi__ZTSPv_FromRuby(state, args[2]);
    void *ret_val = sqlite3_commit_hook(_0, _1, _2);
    return drb_ffi__ZTSPv_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_rollback_hook_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_rollback_hook': wrong number of arguments (%d for 3)", argc);
    sqlite3 *_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    void (*_1)(void *) = drb_ffi__ZTSPFvPvE_FromRuby(state, args[1]);
    void *_2 = drb_ffi__ZTSPv_FromRuby(state, args[2]);
    void *ret_val = sqlite3_rollback_hook(_0, _1, _2);
    return drb_ffi__ZTSPv_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_autovacuum_pages_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 4)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_autovacuum_pages': wrong number of arguments (%d for 4)", argc);
    sqlite3 *db_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    unsigned int (*_1)(void *, const char *, unsigned int, unsigned int, unsigned int) = drb_ffi__ZTSPFjPvPKcjjjE_FromRuby(state, args[1]);
    void *_2 = drb_ffi__ZTSPv_FromRuby(state, args[2]);
    void (*_3)(void *) = drb_ffi__ZTSPFvPvE_FromRuby(state, args[3]);
    int ret_val = sqlite3_autovacuum_pages(db_0, _1, _2, _3);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_update_hook_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_update_hook': wrong number of arguments (%d for 3)", argc);
    sqlite3 *_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    void (*_1)(void *, int, const char *, const char *, sqlite3_int64) = drb_ffi__ZTSPFvPviPKcS1_xE_FromRuby(state, args[1]);
    void *_2 = drb_ffi__ZTSPv_FromRuby(state, args[2]);
    void *ret_val = sqlite3_update_hook(_0, _1, _2);
    return drb_ffi__ZTSPv_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_enable_shared_cache_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_enable_shared_cache': wrong number of arguments (%d for 1)", argc);
    int _0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    int ret_val = sqlite3_enable_shared_cache(_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_release_memory_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_release_memory': wrong number of arguments (%d for 1)", argc);
    int _0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    int ret_val = sqlite3_release_memory(_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_db_release_memory_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_db_release_memory': wrong number of arguments (%d for 1)", argc);
    sqlite3 *_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    int ret_val = sqlite3_db_release_memory(_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_soft_heap_limit64_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_soft_heap_limit64': wrong number of arguments (%d for 1)", argc);
    sqlite3_int64 N_0 = drb_ffi__ZTSx_FromRuby(state, args[0]);
    sqlite3_int64 ret_val = sqlite3_soft_heap_limit64(N_0);
    return drb_ffi__ZTSx_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_hard_heap_limit64_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_hard_heap_limit64': wrong number of arguments (%d for 1)", argc);
    sqlite3_int64 N_0 = drb_ffi__ZTSx_FromRuby(state, args[0]);
    sqlite3_int64 ret_val = sqlite3_hard_heap_limit64(N_0);
    return drb_ffi__ZTSx_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_soft_heap_limit_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_soft_heap_limit': wrong number of arguments (%d for 1)", argc);
    int N_0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    sqlite3_soft_heap_limit(N_0);
    return mrb_nil_value();
}
static mrb_value drb_ffi_sqlite3_table_column_metadata_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 9)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_table_column_metadata': wrong number of arguments (%d for 9)", argc);
    sqlite3 *db_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    char *zDbName_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    char *zTableName_2 = drb_ffi__ZTSPc_FromRuby(state, args[2]);
    char *zColumnName_3 = drb_ffi__ZTSPc_FromRuby(state, args[3]);
    char **pzDataType_4 = drb_ffi__ZTSPPc_FromRuby(state, args[4]);
    char **pzCollSeq_5 = drb_ffi__ZTSPPc_FromRuby(state, args[5]);
    int *pNotNull_6 = drb_ffi__ZTSPi_FromRuby(state, args[6]);
    int *pPrimaryKey_7 = drb_ffi__ZTSPi_FromRuby(state, args[7]);
    int *pAutoinc_8 = drb_ffi__ZTSPi_FromRuby(state, args[8]);
    int ret_val = sqlite3_table_column_metadata(db_0, zDbName_1, zTableName_2, zColumnName_3, pzDataType_4, pzCollSeq_5, pNotNull_6, pPrimaryKey_7, pAutoinc_8);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_load_extension_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 4)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_load_extension': wrong number of arguments (%d for 4)", argc);
    sqlite3 *db_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    char *zFile_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    char *zProc_2 = drb_ffi__ZTSPc_FromRuby(state, args[2]);
    char **pzErrMsg_3 = drb_ffi__ZTSPPc_FromRuby(state, args[3]);
    int ret_val = sqlite3_load_extension(db_0, zFile_1, zProc_2, pzErrMsg_3);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_enable_load_extension_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_enable_load_extension': wrong number of arguments (%d for 2)", argc);
    sqlite3 *db_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    int onoff_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    int ret_val = sqlite3_enable_load_extension(db_0, onoff_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_auto_extension_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_auto_extension': wrong number of arguments (%d for 1)", argc);
    void (*xEntryPoint_0)(void) = drb_ffi__ZTSPFvvE_FromRuby(state, args[0]);
    int ret_val = sqlite3_auto_extension(xEntryPoint_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_cancel_auto_extension_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_cancel_auto_extension': wrong number of arguments (%d for 1)", argc);
    void (*xEntryPoint_0)(void) = drb_ffi__ZTSPFvvE_FromRuby(state, args[0]);
    int ret_val = sqlite3_cancel_auto_extension(xEntryPoint_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_reset_auto_extension_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 0)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_reset_auto_extension': wrong number of arguments (%d for 0)", argc);
    sqlite3_reset_auto_extension();
    return mrb_nil_value();
}
static mrb_value drb_ffi_sqlite3_create_module_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 4)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_create_module': wrong number of arguments (%d for 4)", argc);
    sqlite3 *db_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    char *zName_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    sqlite3_module *p_2 = drb_ffi__ZTSP14sqlite3_module_FromRuby(state, args[2]);
    void *pClientData_3 = drb_ffi__ZTSPv_FromRuby(state, args[3]);
    int ret_val = sqlite3_create_module(db_0, zName_1, p_2, pClientData_3);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_create_module_v2_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 5)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_create_module_v2': wrong number of arguments (%d for 5)", argc);
    sqlite3 *db_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    char *zName_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    sqlite3_module *p_2 = drb_ffi__ZTSP14sqlite3_module_FromRuby(state, args[2]);
    void *pClientData_3 = drb_ffi__ZTSPv_FromRuby(state, args[3]);
    void (*xDestroy_4)(void *) = drb_ffi__ZTSPFvPvE_FromRuby(state, args[4]);
    int ret_val = sqlite3_create_module_v2(db_0, zName_1, p_2, pClientData_3, xDestroy_4);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_drop_modules_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_drop_modules': wrong number of arguments (%d for 2)", argc);
    sqlite3 *db_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    char **azKeep_1 = drb_ffi__ZTSPPc_FromRuby(state, args[1]);
    int ret_val = sqlite3_drop_modules(db_0, azKeep_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_declare_vtab_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_declare_vtab': wrong number of arguments (%d for 2)", argc);
    sqlite3 *_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    char *zSQL_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    int ret_val = sqlite3_declare_vtab(_0, zSQL_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_overload_function_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_overload_function': wrong number of arguments (%d for 3)", argc);
    sqlite3 *_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    char *zFuncName_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    int nArg_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    int ret_val = sqlite3_overload_function(_0, zFuncName_1, nArg_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_blob_open_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 7)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_blob_open': wrong number of arguments (%d for 7)", argc);
    sqlite3 *_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    char *zDb_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    char *zTable_2 = drb_ffi__ZTSPc_FromRuby(state, args[2]);
    char *zColumn_3 = drb_ffi__ZTSPc_FromRuby(state, args[3]);
    sqlite3_int64 iRow_4 = drb_ffi__ZTSx_FromRuby(state, args[4]);
    int flags_5 = drb_ffi__ZTSi_FromRuby(state, args[5]);
    sqlite3_blob **ppBlob_6 = drb_ffi__ZTSPP12sqlite3_blob_FromRuby(state, args[6]);
    int ret_val = sqlite3_blob_open(_0, zDb_1, zTable_2, zColumn_3, iRow_4, flags_5, ppBlob_6);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_blob_reopen_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_blob_reopen': wrong number of arguments (%d for 2)", argc);
    sqlite3_blob *_0 = drb_ffi__ZTSP12sqlite3_blob_FromRuby(state, args[0]);
    sqlite3_int64 _1 = drb_ffi__ZTSx_FromRuby(state, args[1]);
    int ret_val = sqlite3_blob_reopen(_0, _1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_blob_close_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_blob_close': wrong number of arguments (%d for 1)", argc);
    sqlite3_blob *_0 = drb_ffi__ZTSP12sqlite3_blob_FromRuby(state, args[0]);
    int ret_val = sqlite3_blob_close(_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_blob_bytes_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_blob_bytes': wrong number of arguments (%d for 1)", argc);
    sqlite3_blob *_0 = drb_ffi__ZTSP12sqlite3_blob_FromRuby(state, args[0]);
    int ret_val = sqlite3_blob_bytes(_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_blob_read_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 4)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_blob_read': wrong number of arguments (%d for 4)", argc);
    sqlite3_blob *_0 = drb_ffi__ZTSP12sqlite3_blob_FromRuby(state, args[0]);
    void *Z_1 = drb_ffi__ZTSPv_FromRuby(state, args[1]);
    int N_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    int iOffset_3 = drb_ffi__ZTSi_FromRuby(state, args[3]);
    int ret_val = sqlite3_blob_read(_0, Z_1, N_2, iOffset_3);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_blob_write_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 4)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_blob_write': wrong number of arguments (%d for 4)", argc);
    sqlite3_blob *_0 = drb_ffi__ZTSP12sqlite3_blob_FromRuby(state, args[0]);
    void *z_1 = drb_ffi__ZTSPv_FromRuby(state, args[1]);
    int n_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    int iOffset_3 = drb_ffi__ZTSi_FromRuby(state, args[3]);
    int ret_val = sqlite3_blob_write(_0, z_1, n_2, iOffset_3);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_vfs_find_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_vfs_find': wrong number of arguments (%d for 1)", argc);
    char *zVfsName_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    sqlite3_vfs *ret_val = sqlite3_vfs_find(zVfsName_0);
    return drb_ffi__ZTSP11sqlite3_vfs_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_vfs_register_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_vfs_register': wrong number of arguments (%d for 2)", argc);
    sqlite3_vfs *_0 = drb_ffi__ZTSP11sqlite3_vfs_FromRuby(state, args[0]);
    int makeDflt_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    int ret_val = sqlite3_vfs_register(_0, makeDflt_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_vfs_unregister_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_vfs_unregister': wrong number of arguments (%d for 1)", argc);
    sqlite3_vfs *_0 = drb_ffi__ZTSP11sqlite3_vfs_FromRuby(state, args[0]);
    int ret_val = sqlite3_vfs_unregister(_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_mutex_alloc_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_mutex_alloc': wrong number of arguments (%d for 1)", argc);
    int _0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    sqlite3_mutex *ret_val = sqlite3_mutex_alloc(_0);
    return drb_ffi__ZTSP13sqlite3_mutex_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_mutex_free_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_mutex_free': wrong number of arguments (%d for 1)", argc);
    sqlite3_mutex *_0 = drb_ffi__ZTSP13sqlite3_mutex_FromRuby(state, args[0]);
    sqlite3_mutex_free(_0);
    return mrb_nil_value();
}
static mrb_value drb_ffi_sqlite3_mutex_enter_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_mutex_enter': wrong number of arguments (%d for 1)", argc);
    sqlite3_mutex *_0 = drb_ffi__ZTSP13sqlite3_mutex_FromRuby(state, args[0]);
    sqlite3_mutex_enter(_0);
    return mrb_nil_value();
}
static mrb_value drb_ffi_sqlite3_mutex_try_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_mutex_try': wrong number of arguments (%d for 1)", argc);
    sqlite3_mutex *_0 = drb_ffi__ZTSP13sqlite3_mutex_FromRuby(state, args[0]);
    int ret_val = sqlite3_mutex_try(_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_mutex_leave_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_mutex_leave': wrong number of arguments (%d for 1)", argc);
    sqlite3_mutex *_0 = drb_ffi__ZTSP13sqlite3_mutex_FromRuby(state, args[0]);
    sqlite3_mutex_leave(_0);
    return mrb_nil_value();
}
static mrb_value drb_ffi_sqlite3_db_mutex_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_db_mutex': wrong number of arguments (%d for 1)", argc);
    sqlite3 *_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    sqlite3_mutex *ret_val = sqlite3_db_mutex(_0);
    return drb_ffi__ZTSP13sqlite3_mutex_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_file_control_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 4)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_file_control': wrong number of arguments (%d for 4)", argc);
    sqlite3 *_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    char *zDbName_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    int op_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    void *_3 = drb_ffi__ZTSPv_FromRuby(state, args[3]);
    int ret_val = sqlite3_file_control(_0, zDbName_1, op_2, _3);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_keyword_count_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 0)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_keyword_count': wrong number of arguments (%d for 0)", argc);
    int ret_val = sqlite3_keyword_count();
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_keyword_name_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_keyword_name': wrong number of arguments (%d for 3)", argc);
    int _0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    char **_1 = drb_ffi__ZTSPPc_FromRuby(state, args[1]);
    int *_2 = drb_ffi__ZTSPi_FromRuby(state, args[2]);
    int ret_val = sqlite3_keyword_name(_0, _1, _2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_keyword_check_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_keyword_check': wrong number of arguments (%d for 2)", argc);
    char *_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    int _1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    int ret_val = sqlite3_keyword_check(_0, _1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_str_new_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_str_new': wrong number of arguments (%d for 1)", argc);
    sqlite3 *_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    sqlite3_str *ret_val = sqlite3_str_new(_0);
    return drb_ffi__ZTSP11sqlite3_str_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_str_finish_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_str_finish': wrong number of arguments (%d for 1)", argc);
    sqlite3_str *_0 = drb_ffi__ZTSP11sqlite3_str_FromRuby(state, args[0]);
    char *ret_val = sqlite3_str_finish(_0);
    return drb_ffi__ZTSPc_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_str_vappendf_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_str_vappendf': wrong number of arguments (%d for 3)", argc);
    sqlite3_str *_0 = drb_ffi__ZTSP11sqlite3_str_FromRuby(state, args[0]);
    char *zFormat_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    char *_2 = drb_ffi__ZTSPc_FromRuby(state, args[2]);
    sqlite3_str_vappendf(_0, zFormat_1, _2);
    return mrb_nil_value();
}
static mrb_value drb_ffi_sqlite3_str_append_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_str_append': wrong number of arguments (%d for 3)", argc);
    sqlite3_str *_0 = drb_ffi__ZTSP11sqlite3_str_FromRuby(state, args[0]);
    char *zIn_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    int N_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    sqlite3_str_append(_0, zIn_1, N_2);
    return mrb_nil_value();
}
static mrb_value drb_ffi_sqlite3_str_appendall_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_str_appendall': wrong number of arguments (%d for 2)", argc);
    sqlite3_str *_0 = drb_ffi__ZTSP11sqlite3_str_FromRuby(state, args[0]);
    char *zIn_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    sqlite3_str_appendall(_0, zIn_1);
    return mrb_nil_value();
}
static mrb_value drb_ffi_sqlite3_str_appendchar_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_str_appendchar': wrong number of arguments (%d for 3)", argc);
    sqlite3_str *_0 = drb_ffi__ZTSP11sqlite3_str_FromRuby(state, args[0]);
    int N_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    char C_2 = drb_ffi__ZTSc_FromRuby(state, args[2]);
    sqlite3_str_appendchar(_0, N_1, C_2);
    return mrb_nil_value();
}
static mrb_value drb_ffi_sqlite3_str_reset_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_str_reset': wrong number of arguments (%d for 1)", argc);
    sqlite3_str *_0 = drb_ffi__ZTSP11sqlite3_str_FromRuby(state, args[0]);
    sqlite3_str_reset(_0);
    return mrb_nil_value();
}
static mrb_value drb_ffi_sqlite3_str_errcode_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_str_errcode': wrong number of arguments (%d for 1)", argc);
    sqlite3_str *_0 = drb_ffi__ZTSP11sqlite3_str_FromRuby(state, args[0]);
    int ret_val = sqlite3_str_errcode(_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_str_length_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_str_length': wrong number of arguments (%d for 1)", argc);
    sqlite3_str *_0 = drb_ffi__ZTSP11sqlite3_str_FromRuby(state, args[0]);
    int ret_val = sqlite3_str_length(_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_str_value_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_str_value': wrong number of arguments (%d for 1)", argc);
    sqlite3_str *_0 = drb_ffi__ZTSP11sqlite3_str_FromRuby(state, args[0]);
    char *ret_val = sqlite3_str_value(_0);
    return drb_ffi__ZTSPc_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_status_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 4)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_status': wrong number of arguments (%d for 4)", argc);
    int op_0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    int *pCurrent_1 = drb_ffi__ZTSPi_FromRuby(state, args[1]);
    int *pHighwater_2 = drb_ffi__ZTSPi_FromRuby(state, args[2]);
    int resetFlag_3 = drb_ffi__ZTSi_FromRuby(state, args[3]);
    int ret_val = sqlite3_status(op_0, pCurrent_1, pHighwater_2, resetFlag_3);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_status64_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 4)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_status64': wrong number of arguments (%d for 4)", argc);
    int op_0 = drb_ffi__ZTSi_FromRuby(state, args[0]);
    sqlite3_int64 *pCurrent_1 = drb_ffi__ZTSPx_FromRuby(state, args[1]);
    sqlite3_int64 *pHighwater_2 = drb_ffi__ZTSPx_FromRuby(state, args[2]);
    int resetFlag_3 = drb_ffi__ZTSi_FromRuby(state, args[3]);
    int ret_val = sqlite3_status64(op_0, pCurrent_1, pHighwater_2, resetFlag_3);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_db_status_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 5)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_db_status': wrong number of arguments (%d for 5)", argc);
    sqlite3 *_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    int op_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    int *pCur_2 = drb_ffi__ZTSPi_FromRuby(state, args[2]);
    int *pHiwtr_3 = drb_ffi__ZTSPi_FromRuby(state, args[3]);
    int resetFlg_4 = drb_ffi__ZTSi_FromRuby(state, args[4]);
    int ret_val = sqlite3_db_status(_0, op_1, pCur_2, pHiwtr_3, resetFlg_4);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_stmt_status_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_stmt_status': wrong number of arguments (%d for 3)", argc);
    sqlite3_stmt *_0 = drb_ffi__ZTSP12sqlite3_stmt_FromRuby(state, args[0]);
    int op_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    int resetFlg_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    int ret_val = sqlite3_stmt_status(_0, op_1, resetFlg_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_backup_init_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 4)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_backup_init': wrong number of arguments (%d for 4)", argc);
    sqlite3 *pDest_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    char *zDestName_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    sqlite3 *pSource_2 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[2]);
    char *zSourceName_3 = drb_ffi__ZTSPc_FromRuby(state, args[3]);
    sqlite3_backup *ret_val = sqlite3_backup_init(pDest_0, zDestName_1, pSource_2, zSourceName_3);
    return drb_ffi__ZTSP14sqlite3_backup_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_backup_step_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_backup_step': wrong number of arguments (%d for 2)", argc);
    sqlite3_backup *p_0 = drb_ffi__ZTSP14sqlite3_backup_FromRuby(state, args[0]);
    int nPage_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    int ret_val = sqlite3_backup_step(p_0, nPage_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_backup_finish_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_backup_finish': wrong number of arguments (%d for 1)", argc);
    sqlite3_backup *p_0 = drb_ffi__ZTSP14sqlite3_backup_FromRuby(state, args[0]);
    int ret_val = sqlite3_backup_finish(p_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_backup_remaining_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_backup_remaining': wrong number of arguments (%d for 1)", argc);
    sqlite3_backup *p_0 = drb_ffi__ZTSP14sqlite3_backup_FromRuby(state, args[0]);
    int ret_val = sqlite3_backup_remaining(p_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_backup_pagecount_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_backup_pagecount': wrong number of arguments (%d for 1)", argc);
    sqlite3_backup *p_0 = drb_ffi__ZTSP14sqlite3_backup_FromRuby(state, args[0]);
    int ret_val = sqlite3_backup_pagecount(p_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_stricmp_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_stricmp': wrong number of arguments (%d for 2)", argc);
    char *_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    char *_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    int ret_val = sqlite3_stricmp(_0, _1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_strnicmp_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_strnicmp': wrong number of arguments (%d for 3)", argc);
    char *_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    char *_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    int _2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    int ret_val = sqlite3_strnicmp(_0, _1, _2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_strglob_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_strglob': wrong number of arguments (%d for 2)", argc);
    char *zGlob_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    char *zStr_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    int ret_val = sqlite3_strglob(zGlob_0, zStr_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_strlike_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_strlike': wrong number of arguments (%d for 3)", argc);
    char *zGlob_0 = drb_ffi__ZTSPc_FromRuby(state, args[0]);
    char *zStr_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    unsigned int cEsc_2 = drb_ffi__ZTSj_FromRuby(state, args[2]);
    int ret_val = sqlite3_strlike(zGlob_0, zStr_1, cEsc_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_wal_hook_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_wal_hook': wrong number of arguments (%d for 3)", argc);
    sqlite3 *_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    int (*_1)(void *, sqlite3 *, const char *, int) = drb_ffi__ZTSPFiPvP7sqlite3PKciE_FromRuby(state, args[1]);
    void *_2 = drb_ffi__ZTSPv_FromRuby(state, args[2]);
    void *ret_val = sqlite3_wal_hook(_0, _1, _2);
    return drb_ffi__ZTSPv_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_wal_autocheckpoint_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_wal_autocheckpoint': wrong number of arguments (%d for 2)", argc);
    sqlite3 *db_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    int N_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    int ret_val = sqlite3_wal_autocheckpoint(db_0, N_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_wal_checkpoint_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_wal_checkpoint': wrong number of arguments (%d for 2)", argc);
    sqlite3 *db_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    char *zDb_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    int ret_val = sqlite3_wal_checkpoint(db_0, zDb_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_wal_checkpoint_v2_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 5)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_wal_checkpoint_v2': wrong number of arguments (%d for 5)", argc);
    sqlite3 *db_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    char *zDb_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    int eMode_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    int *pnLog_3 = drb_ffi__ZTSPi_FromRuby(state, args[3]);
    int *pnCkpt_4 = drb_ffi__ZTSPi_FromRuby(state, args[4]);
    int ret_val = sqlite3_wal_checkpoint_v2(db_0, zDb_1, eMode_2, pnLog_3, pnCkpt_4);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_vtab_on_conflict_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_vtab_on_conflict': wrong number of arguments (%d for 1)", argc);
    sqlite3 *_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    int ret_val = sqlite3_vtab_on_conflict(_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_vtab_nochange_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_vtab_nochange': wrong number of arguments (%d for 1)", argc);
    sqlite3_context *_0 = drb_ffi__ZTSP15sqlite3_context_FromRuby(state, args[0]);
    int ret_val = sqlite3_vtab_nochange(_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_vtab_collation_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_vtab_collation': wrong number of arguments (%d for 2)", argc);
    sqlite3_index_info *_0 = drb_ffi__ZTSP18sqlite3_index_info_FromRuby(state, args[0]);
    int _1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    char *ret_val = sqlite3_vtab_collation(_0, _1);
    return drb_ffi__ZTSPc_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_vtab_distinct_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_vtab_distinct': wrong number of arguments (%d for 1)", argc);
    sqlite3_index_info *_0 = drb_ffi__ZTSP18sqlite3_index_info_FromRuby(state, args[0]);
    int ret_val = sqlite3_vtab_distinct(_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_vtab_in_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_vtab_in': wrong number of arguments (%d for 3)", argc);
    sqlite3_index_info *_0 = drb_ffi__ZTSP18sqlite3_index_info_FromRuby(state, args[0]);
    int iCons_1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    int bHandle_2 = drb_ffi__ZTSi_FromRuby(state, args[2]);
    int ret_val = sqlite3_vtab_in(_0, iCons_1, bHandle_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_vtab_in_first_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_vtab_in_first': wrong number of arguments (%d for 2)", argc);
    sqlite3_value *pVal_0 = drb_ffi__ZTSP13sqlite3_value_FromRuby(state, args[0]);
    sqlite3_value **ppOut_1 = drb_ffi__ZTSPP13sqlite3_value_FromRuby(state, args[1]);
    int ret_val = sqlite3_vtab_in_first(pVal_0, ppOut_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_vtab_in_next_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 2)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_vtab_in_next': wrong number of arguments (%d for 2)", argc);
    sqlite3_value *pVal_0 = drb_ffi__ZTSP13sqlite3_value_FromRuby(state, args[0]);
    sqlite3_value **ppOut_1 = drb_ffi__ZTSPP13sqlite3_value_FromRuby(state, args[1]);
    int ret_val = sqlite3_vtab_in_next(pVal_0, ppOut_1);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_vtab_rhs_value_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 3)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_vtab_rhs_value': wrong number of arguments (%d for 3)", argc);
    sqlite3_index_info *_0 = drb_ffi__ZTSP18sqlite3_index_info_FromRuby(state, args[0]);
    int _1 = drb_ffi__ZTSi_FromRuby(state, args[1]);
    sqlite3_value **ppVal_2 = drb_ffi__ZTSPP13sqlite3_value_FromRuby(state, args[2]);
    int ret_val = sqlite3_vtab_rhs_value(_0, _1, ppVal_2);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_db_cacheflush_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_db_cacheflush': wrong number of arguments (%d for 1)", argc);
    sqlite3 *_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    int ret_val = sqlite3_db_cacheflush(_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_system_errno_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 1)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_system_errno': wrong number of arguments (%d for 1)", argc);
    sqlite3 *_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    int ret_val = sqlite3_system_errno(_0);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_serialize_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 4)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_serialize': wrong number of arguments (%d for 4)", argc);
    sqlite3 *db_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    char *zSchema_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    sqlite3_int64 *piSize_2 = drb_ffi__ZTSPx_FromRuby(state, args[2]);
    unsigned int mFlags_3 = drb_ffi__ZTSj_FromRuby(state, args[3]);
    unsigned char *ret_val = sqlite3_serialize(db_0, zSchema_1, piSize_2, mFlags_3);
    return drb_ffi__ZTSPh_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_deserialize_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 6)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_deserialize': wrong number of arguments (%d for 6)", argc);
    sqlite3 *db_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    char *zSchema_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    unsigned char *pData_2 = drb_ffi__ZTSPh_FromRuby(state, args[2]);
    sqlite3_int64 szDb_3 = drb_ffi__ZTSx_FromRuby(state, args[3]);
    sqlite3_int64 szBuf_4 = drb_ffi__ZTSx_FromRuby(state, args[4]);
    unsigned int mFlags_5 = drb_ffi__ZTSj_FromRuby(state, args[5]);
    int ret_val = sqlite3_deserialize(db_0, zSchema_1, pData_2, szDb_3, szBuf_4, mFlags_5);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_rtree_geometry_callback_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 4)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_rtree_geometry_callback': wrong number of arguments (%d for 4)", argc);
    sqlite3 *db_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    char *zGeom_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    int (*xGeom_2)(sqlite3_rtree_geometry *, int, sqlite3_rtree_dbl *, int *) = drb_ffi__ZTSPFiP22sqlite3_rtree_geometryiPdPiE_FromRuby(state, args[2]);
    void *pContext_3 = drb_ffi__ZTSPv_FromRuby(state, args[3]);
    int ret_val = sqlite3_rtree_geometry_callback(db_0, zGeom_1, xGeom_2, pContext_3);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
static mrb_value drb_ffi_sqlite3_rtree_query_callback_Binding(mrb_state *state, mrb_value value) {
    mrb_value *args = 0;
    mrb_int argc = 0;
    drb_api->mrb_get_args(state, "*", &args, &argc);
    if (argc != 5)
        drb_api->mrb_raisef(state, drb_api->drb_getargument_error(state), "'sqlite3_rtree_query_callback': wrong number of arguments (%d for 5)", argc);
    sqlite3 *db_0 = drb_ffi__ZTSP7sqlite3_FromRuby(state, args[0]);
    char *zQueryFunc_1 = drb_ffi__ZTSPc_FromRuby(state, args[1]);
    int (*xQueryFunc_2)(sqlite3_rtree_query_info *) = drb_ffi__ZTSPFiP24sqlite3_rtree_query_infoE_FromRuby(state, args[2]);
    void *pContext_3 = drb_ffi__ZTSPv_FromRuby(state, args[3]);
    void (*xDestructor_4)(void *) = drb_ffi__ZTSPFvPvE_FromRuby(state, args[4]);
    int ret_val = sqlite3_rtree_query_callback(db_0, zQueryFunc_1, xQueryFunc_2, pContext_3, xDestructor_4);
    return drb_ffi__ZTSi_ToRuby(state, ret_val);
}
DRB_FFI_EXPORT
void drb_register_c_extensions_with_api(mrb_state *state, struct drb_api_t *api) {
    drb_api = api;
    struct RClass *FFI = drb_api->mrb_module_get(state, "FFI");
    struct RClass *module = drb_api->mrb_define_module_under(state, FFI, "LIBSQLITE3");
    struct RClass *object_class = state->object_class;
    drb_api->mrb_define_module_function(state, module, "__debugbreak", drb_ffi___debugbreak_Binding, MRB_ARGS_REQ(0));
    drb_api->mrb_define_module_function(state, module, "__debugbreak", drb_ffi___debugbreak_Binding, MRB_ARGS_REQ(0));
    drb_api->mrb_define_module_function(state, module, "__mingw_get_crt_info", drb_ffi___mingw_get_crt_info_Binding, MRB_ARGS_REQ(0));
    drb_api->mrb_define_module_function(state, module, "sqlite3_libversion", drb_ffi_sqlite3_libversion_Binding, MRB_ARGS_REQ(0));
    drb_api->mrb_define_module_function(state, module, "sqlite3_sourceid", drb_ffi_sqlite3_sourceid_Binding, MRB_ARGS_REQ(0));
    drb_api->mrb_define_module_function(state, module, "sqlite3_libversion_number", drb_ffi_sqlite3_libversion_number_Binding, MRB_ARGS_REQ(0));
    drb_api->mrb_define_module_function(state, module, "sqlite3_compileoption_used", drb_ffi_sqlite3_compileoption_used_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_compileoption_get", drb_ffi_sqlite3_compileoption_get_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_threadsafe", drb_ffi_sqlite3_threadsafe_Binding, MRB_ARGS_REQ(0));
    drb_api->mrb_define_module_function(state, module, "sqlite3_close", drb_ffi_sqlite3_close_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_close_v2", drb_ffi_sqlite3_close_v2_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_exec", drb_ffi_sqlite3_exec_Binding, MRB_ARGS_REQ(5));
    drb_api->mrb_define_module_function(state, module, "sqlite3_initialize", drb_ffi_sqlite3_initialize_Binding, MRB_ARGS_REQ(0));
    drb_api->mrb_define_module_function(state, module, "sqlite3_shutdown", drb_ffi_sqlite3_shutdown_Binding, MRB_ARGS_REQ(0));
    drb_api->mrb_define_module_function(state, module, "sqlite3_os_init", drb_ffi_sqlite3_os_init_Binding, MRB_ARGS_REQ(0));
    drb_api->mrb_define_module_function(state, module, "sqlite3_os_end", drb_ffi_sqlite3_os_end_Binding, MRB_ARGS_REQ(0));
    drb_api->mrb_define_module_function(state, module, "sqlite3_extended_result_codes", drb_ffi_sqlite3_extended_result_codes_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_last_insert_rowid", drb_ffi_sqlite3_last_insert_rowid_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_set_last_insert_rowid", drb_ffi_sqlite3_set_last_insert_rowid_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_changes", drb_ffi_sqlite3_changes_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_changes64", drb_ffi_sqlite3_changes64_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_total_changes", drb_ffi_sqlite3_total_changes_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_total_changes64", drb_ffi_sqlite3_total_changes64_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_interrupt", drb_ffi_sqlite3_interrupt_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_complete", drb_ffi_sqlite3_complete_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_complete16", drb_ffi_sqlite3_complete16_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_busy_handler", drb_ffi_sqlite3_busy_handler_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "sqlite3_busy_timeout", drb_ffi_sqlite3_busy_timeout_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_get_table", drb_ffi_sqlite3_get_table_Binding, MRB_ARGS_REQ(6));
    drb_api->mrb_define_module_function(state, module, "sqlite3_free_table", drb_ffi_sqlite3_free_table_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_vmprintf", drb_ffi_sqlite3_vmprintf_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_vsnprintf", drb_ffi_sqlite3_vsnprintf_Binding, MRB_ARGS_REQ(4));
    drb_api->mrb_define_module_function(state, module, "sqlite3_malloc", drb_ffi_sqlite3_malloc_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_malloc64", drb_ffi_sqlite3_malloc64_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_realloc", drb_ffi_sqlite3_realloc_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_realloc64", drb_ffi_sqlite3_realloc64_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_free", drb_ffi_sqlite3_free_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_msize", drb_ffi_sqlite3_msize_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_memory_used", drb_ffi_sqlite3_memory_used_Binding, MRB_ARGS_REQ(0));
    drb_api->mrb_define_module_function(state, module, "sqlite3_memory_highwater", drb_ffi_sqlite3_memory_highwater_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_randomness", drb_ffi_sqlite3_randomness_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_set_authorizer", drb_ffi_sqlite3_set_authorizer_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "sqlite3_trace", drb_ffi_sqlite3_trace_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "sqlite3_profile", drb_ffi_sqlite3_profile_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "sqlite3_trace_v2", drb_ffi_sqlite3_trace_v2_Binding, MRB_ARGS_REQ(4));
    drb_api->mrb_define_module_function(state, module, "sqlite3_progress_handler", drb_ffi_sqlite3_progress_handler_Binding, MRB_ARGS_REQ(4));
    drb_api->mrb_define_module_function(state, module, "sqlite3_open", drb_ffi_sqlite3_open_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_open16", drb_ffi_sqlite3_open16_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_open_v2", drb_ffi_sqlite3_open_v2_Binding, MRB_ARGS_REQ(4));
    drb_api->mrb_define_module_function(state, module, "sqlite3_uri_parameter", drb_ffi_sqlite3_uri_parameter_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_uri_boolean", drb_ffi_sqlite3_uri_boolean_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "sqlite3_uri_int64", drb_ffi_sqlite3_uri_int64_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "sqlite3_uri_key", drb_ffi_sqlite3_uri_key_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_filename_database", drb_ffi_sqlite3_filename_database_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_filename_journal", drb_ffi_sqlite3_filename_journal_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_filename_wal", drb_ffi_sqlite3_filename_wal_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_database_file_object", drb_ffi_sqlite3_database_file_object_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_create_filename", drb_ffi_sqlite3_create_filename_Binding, MRB_ARGS_REQ(5));
    drb_api->mrb_define_module_function(state, module, "sqlite3_free_filename", drb_ffi_sqlite3_free_filename_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_errcode", drb_ffi_sqlite3_errcode_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_extended_errcode", drb_ffi_sqlite3_extended_errcode_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_errmsg", drb_ffi_sqlite3_errmsg_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_errmsg16", drb_ffi_sqlite3_errmsg16_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_errstr", drb_ffi_sqlite3_errstr_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_error_offset", drb_ffi_sqlite3_error_offset_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_limit", drb_ffi_sqlite3_limit_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "sqlite3_prepare", drb_ffi_sqlite3_prepare_Binding, MRB_ARGS_REQ(5));
    drb_api->mrb_define_module_function(state, module, "sqlite3_prepare_v2", drb_ffi_sqlite3_prepare_v2_Binding, MRB_ARGS_REQ(5));
    drb_api->mrb_define_module_function(state, module, "sqlite3_prepare_v3", drb_ffi_sqlite3_prepare_v3_Binding, MRB_ARGS_REQ(6));
    drb_api->mrb_define_module_function(state, module, "sqlite3_prepare16", drb_ffi_sqlite3_prepare16_Binding, MRB_ARGS_REQ(5));
    drb_api->mrb_define_module_function(state, module, "sqlite3_prepare16_v2", drb_ffi_sqlite3_prepare16_v2_Binding, MRB_ARGS_REQ(5));
    drb_api->mrb_define_module_function(state, module, "sqlite3_prepare16_v3", drb_ffi_sqlite3_prepare16_v3_Binding, MRB_ARGS_REQ(6));
    drb_api->mrb_define_module_function(state, module, "sqlite3_sql", drb_ffi_sqlite3_sql_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_expanded_sql", drb_ffi_sqlite3_expanded_sql_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_stmt_readonly", drb_ffi_sqlite3_stmt_readonly_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_stmt_isexplain", drb_ffi_sqlite3_stmt_isexplain_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_stmt_busy", drb_ffi_sqlite3_stmt_busy_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_bind_blob", drb_ffi_sqlite3_bind_blob_Binding, MRB_ARGS_REQ(5));
    drb_api->mrb_define_module_function(state, module, "sqlite3_bind_blob64", drb_ffi_sqlite3_bind_blob64_Binding, MRB_ARGS_REQ(5));
    drb_api->mrb_define_module_function(state, module, "sqlite3_bind_double", drb_ffi_sqlite3_bind_double_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "sqlite3_bind_int", drb_ffi_sqlite3_bind_int_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "sqlite3_bind_int64", drb_ffi_sqlite3_bind_int64_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "sqlite3_bind_null", drb_ffi_sqlite3_bind_null_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_bind_text", drb_ffi_sqlite3_bind_text_Binding, MRB_ARGS_REQ(5));
    drb_api->mrb_define_module_function(state, module, "sqlite3_bind_text16", drb_ffi_sqlite3_bind_text16_Binding, MRB_ARGS_REQ(5));
    drb_api->mrb_define_module_function(state, module, "sqlite3_bind_text64", drb_ffi_sqlite3_bind_text64_Binding, MRB_ARGS_REQ(6));
    drb_api->mrb_define_module_function(state, module, "sqlite3_bind_value", drb_ffi_sqlite3_bind_value_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "sqlite3_bind_pointer", drb_ffi_sqlite3_bind_pointer_Binding, MRB_ARGS_REQ(5));
    drb_api->mrb_define_module_function(state, module, "sqlite3_bind_zeroblob", drb_ffi_sqlite3_bind_zeroblob_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "sqlite3_bind_zeroblob64", drb_ffi_sqlite3_bind_zeroblob64_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "sqlite3_bind_parameter_count", drb_ffi_sqlite3_bind_parameter_count_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_bind_parameter_name", drb_ffi_sqlite3_bind_parameter_name_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_bind_parameter_index", drb_ffi_sqlite3_bind_parameter_index_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_clear_bindings", drb_ffi_sqlite3_clear_bindings_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_column_count", drb_ffi_sqlite3_column_count_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_column_name", drb_ffi_sqlite3_column_name_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_column_name16", drb_ffi_sqlite3_column_name16_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_column_database_name", drb_ffi_sqlite3_column_database_name_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_column_database_name16", drb_ffi_sqlite3_column_database_name16_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_column_table_name", drb_ffi_sqlite3_column_table_name_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_column_table_name16", drb_ffi_sqlite3_column_table_name16_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_column_origin_name", drb_ffi_sqlite3_column_origin_name_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_column_origin_name16", drb_ffi_sqlite3_column_origin_name16_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_column_decltype", drb_ffi_sqlite3_column_decltype_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_column_decltype16", drb_ffi_sqlite3_column_decltype16_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_step", drb_ffi_sqlite3_step_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_data_count", drb_ffi_sqlite3_data_count_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_column_blob", drb_ffi_sqlite3_column_blob_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_column_double", drb_ffi_sqlite3_column_double_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_column_int", drb_ffi_sqlite3_column_int_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_column_int64", drb_ffi_sqlite3_column_int64_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_column_text", drb_ffi_sqlite3_column_text_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_column_text16", drb_ffi_sqlite3_column_text16_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_column_value", drb_ffi_sqlite3_column_value_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_column_bytes", drb_ffi_sqlite3_column_bytes_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_column_bytes16", drb_ffi_sqlite3_column_bytes16_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_column_type", drb_ffi_sqlite3_column_type_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_finalize", drb_ffi_sqlite3_finalize_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_reset", drb_ffi_sqlite3_reset_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_create_function", drb_ffi_sqlite3_create_function_Binding, MRB_ARGS_REQ(8));
    drb_api->mrb_define_module_function(state, module, "sqlite3_create_function16", drb_ffi_sqlite3_create_function16_Binding, MRB_ARGS_REQ(8));
    drb_api->mrb_define_module_function(state, module, "sqlite3_create_function_v2", drb_ffi_sqlite3_create_function_v2_Binding, MRB_ARGS_REQ(9));
    drb_api->mrb_define_module_function(state, module, "sqlite3_create_window_function", drb_ffi_sqlite3_create_window_function_Binding, MRB_ARGS_REQ(10));
    drb_api->mrb_define_module_function(state, module, "sqlite3_aggregate_count", drb_ffi_sqlite3_aggregate_count_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_expired", drb_ffi_sqlite3_expired_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_transfer_bindings", drb_ffi_sqlite3_transfer_bindings_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_global_recover", drb_ffi_sqlite3_global_recover_Binding, MRB_ARGS_REQ(0));
    drb_api->mrb_define_module_function(state, module, "sqlite3_thread_cleanup", drb_ffi_sqlite3_thread_cleanup_Binding, MRB_ARGS_REQ(0));
    drb_api->mrb_define_module_function(state, module, "sqlite3_memory_alarm", drb_ffi_sqlite3_memory_alarm_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "sqlite3_value_blob", drb_ffi_sqlite3_value_blob_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_value_double", drb_ffi_sqlite3_value_double_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_value_int", drb_ffi_sqlite3_value_int_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_value_int64", drb_ffi_sqlite3_value_int64_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_value_pointer", drb_ffi_sqlite3_value_pointer_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_value_text", drb_ffi_sqlite3_value_text_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_value_text16", drb_ffi_sqlite3_value_text16_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_value_text16le", drb_ffi_sqlite3_value_text16le_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_value_text16be", drb_ffi_sqlite3_value_text16be_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_value_bytes", drb_ffi_sqlite3_value_bytes_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_value_bytes16", drb_ffi_sqlite3_value_bytes16_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_value_type", drb_ffi_sqlite3_value_type_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_value_numeric_type", drb_ffi_sqlite3_value_numeric_type_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_value_nochange", drb_ffi_sqlite3_value_nochange_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_value_frombind", drb_ffi_sqlite3_value_frombind_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_value_subtype", drb_ffi_sqlite3_value_subtype_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_value_dup", drb_ffi_sqlite3_value_dup_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_value_free", drb_ffi_sqlite3_value_free_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_aggregate_context", drb_ffi_sqlite3_aggregate_context_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_user_data", drb_ffi_sqlite3_user_data_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_context_db_handle", drb_ffi_sqlite3_context_db_handle_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_get_auxdata", drb_ffi_sqlite3_get_auxdata_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_set_auxdata", drb_ffi_sqlite3_set_auxdata_Binding, MRB_ARGS_REQ(4));
    drb_api->mrb_define_module_function(state, module, "sqlite3_result_blob", drb_ffi_sqlite3_result_blob_Binding, MRB_ARGS_REQ(4));
    drb_api->mrb_define_module_function(state, module, "sqlite3_result_blob64", drb_ffi_sqlite3_result_blob64_Binding, MRB_ARGS_REQ(4));
    drb_api->mrb_define_module_function(state, module, "sqlite3_result_double", drb_ffi_sqlite3_result_double_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_result_error", drb_ffi_sqlite3_result_error_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "sqlite3_result_error16", drb_ffi_sqlite3_result_error16_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "sqlite3_result_error_toobig", drb_ffi_sqlite3_result_error_toobig_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_result_error_nomem", drb_ffi_sqlite3_result_error_nomem_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_result_error_code", drb_ffi_sqlite3_result_error_code_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_result_int", drb_ffi_sqlite3_result_int_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_result_int64", drb_ffi_sqlite3_result_int64_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_result_null", drb_ffi_sqlite3_result_null_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_result_text", drb_ffi_sqlite3_result_text_Binding, MRB_ARGS_REQ(4));
    drb_api->mrb_define_module_function(state, module, "sqlite3_result_text64", drb_ffi_sqlite3_result_text64_Binding, MRB_ARGS_REQ(5));
    drb_api->mrb_define_module_function(state, module, "sqlite3_result_text16", drb_ffi_sqlite3_result_text16_Binding, MRB_ARGS_REQ(4));
    drb_api->mrb_define_module_function(state, module, "sqlite3_result_text16le", drb_ffi_sqlite3_result_text16le_Binding, MRB_ARGS_REQ(4));
    drb_api->mrb_define_module_function(state, module, "sqlite3_result_text16be", drb_ffi_sqlite3_result_text16be_Binding, MRB_ARGS_REQ(4));
    drb_api->mrb_define_module_function(state, module, "sqlite3_result_value", drb_ffi_sqlite3_result_value_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_result_pointer", drb_ffi_sqlite3_result_pointer_Binding, MRB_ARGS_REQ(4));
    drb_api->mrb_define_module_function(state, module, "sqlite3_result_zeroblob", drb_ffi_sqlite3_result_zeroblob_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_result_zeroblob64", drb_ffi_sqlite3_result_zeroblob64_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_result_subtype", drb_ffi_sqlite3_result_subtype_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_create_collation", drb_ffi_sqlite3_create_collation_Binding, MRB_ARGS_REQ(5));
    drb_api->mrb_define_module_function(state, module, "sqlite3_create_collation_v2", drb_ffi_sqlite3_create_collation_v2_Binding, MRB_ARGS_REQ(6));
    drb_api->mrb_define_module_function(state, module, "sqlite3_create_collation16", drb_ffi_sqlite3_create_collation16_Binding, MRB_ARGS_REQ(5));
    drb_api->mrb_define_module_function(state, module, "sqlite3_collation_needed", drb_ffi_sqlite3_collation_needed_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "sqlite3_collation_needed16", drb_ffi_sqlite3_collation_needed16_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "sqlite3_sleep", drb_ffi_sqlite3_sleep_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_win32_set_directory", drb_ffi_sqlite3_win32_set_directory_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_win32_set_directory8", drb_ffi_sqlite3_win32_set_directory8_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_win32_set_directory16", drb_ffi_sqlite3_win32_set_directory16_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_get_autocommit", drb_ffi_sqlite3_get_autocommit_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_db_handle", drb_ffi_sqlite3_db_handle_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_db_filename", drb_ffi_sqlite3_db_filename_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_db_readonly", drb_ffi_sqlite3_db_readonly_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_txn_state", drb_ffi_sqlite3_txn_state_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_next_stmt", drb_ffi_sqlite3_next_stmt_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_commit_hook", drb_ffi_sqlite3_commit_hook_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "sqlite3_rollback_hook", drb_ffi_sqlite3_rollback_hook_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "sqlite3_autovacuum_pages", drb_ffi_sqlite3_autovacuum_pages_Binding, MRB_ARGS_REQ(4));
    drb_api->mrb_define_module_function(state, module, "sqlite3_update_hook", drb_ffi_sqlite3_update_hook_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "sqlite3_enable_shared_cache", drb_ffi_sqlite3_enable_shared_cache_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_release_memory", drb_ffi_sqlite3_release_memory_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_db_release_memory", drb_ffi_sqlite3_db_release_memory_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_soft_heap_limit64", drb_ffi_sqlite3_soft_heap_limit64_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_hard_heap_limit64", drb_ffi_sqlite3_hard_heap_limit64_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_soft_heap_limit", drb_ffi_sqlite3_soft_heap_limit_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_table_column_metadata", drb_ffi_sqlite3_table_column_metadata_Binding, MRB_ARGS_REQ(9));
    drb_api->mrb_define_module_function(state, module, "sqlite3_load_extension", drb_ffi_sqlite3_load_extension_Binding, MRB_ARGS_REQ(4));
    drb_api->mrb_define_module_function(state, module, "sqlite3_enable_load_extension", drb_ffi_sqlite3_enable_load_extension_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_auto_extension", drb_ffi_sqlite3_auto_extension_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_cancel_auto_extension", drb_ffi_sqlite3_cancel_auto_extension_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_reset_auto_extension", drb_ffi_sqlite3_reset_auto_extension_Binding, MRB_ARGS_REQ(0));
    drb_api->mrb_define_module_function(state, module, "sqlite3_create_module", drb_ffi_sqlite3_create_module_Binding, MRB_ARGS_REQ(4));
    drb_api->mrb_define_module_function(state, module, "sqlite3_create_module_v2", drb_ffi_sqlite3_create_module_v2_Binding, MRB_ARGS_REQ(5));
    drb_api->mrb_define_module_function(state, module, "sqlite3_drop_modules", drb_ffi_sqlite3_drop_modules_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_declare_vtab", drb_ffi_sqlite3_declare_vtab_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_overload_function", drb_ffi_sqlite3_overload_function_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "sqlite3_blob_open", drb_ffi_sqlite3_blob_open_Binding, MRB_ARGS_REQ(7));
    drb_api->mrb_define_module_function(state, module, "sqlite3_blob_reopen", drb_ffi_sqlite3_blob_reopen_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_blob_close", drb_ffi_sqlite3_blob_close_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_blob_bytes", drb_ffi_sqlite3_blob_bytes_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_blob_read", drb_ffi_sqlite3_blob_read_Binding, MRB_ARGS_REQ(4));
    drb_api->mrb_define_module_function(state, module, "sqlite3_blob_write", drb_ffi_sqlite3_blob_write_Binding, MRB_ARGS_REQ(4));
    drb_api->mrb_define_module_function(state, module, "sqlite3_vfs_find", drb_ffi_sqlite3_vfs_find_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_vfs_register", drb_ffi_sqlite3_vfs_register_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_vfs_unregister", drb_ffi_sqlite3_vfs_unregister_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_mutex_alloc", drb_ffi_sqlite3_mutex_alloc_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_mutex_free", drb_ffi_sqlite3_mutex_free_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_mutex_enter", drb_ffi_sqlite3_mutex_enter_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_mutex_try", drb_ffi_sqlite3_mutex_try_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_mutex_leave", drb_ffi_sqlite3_mutex_leave_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_db_mutex", drb_ffi_sqlite3_db_mutex_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_file_control", drb_ffi_sqlite3_file_control_Binding, MRB_ARGS_REQ(4));
    drb_api->mrb_define_module_function(state, module, "sqlite3_keyword_count", drb_ffi_sqlite3_keyword_count_Binding, MRB_ARGS_REQ(0));
    drb_api->mrb_define_module_function(state, module, "sqlite3_keyword_name", drb_ffi_sqlite3_keyword_name_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "sqlite3_keyword_check", drb_ffi_sqlite3_keyword_check_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_str_new", drb_ffi_sqlite3_str_new_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_str_finish", drb_ffi_sqlite3_str_finish_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_str_vappendf", drb_ffi_sqlite3_str_vappendf_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "sqlite3_str_append", drb_ffi_sqlite3_str_append_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "sqlite3_str_appendall", drb_ffi_sqlite3_str_appendall_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_str_appendchar", drb_ffi_sqlite3_str_appendchar_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "sqlite3_str_reset", drb_ffi_sqlite3_str_reset_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_str_errcode", drb_ffi_sqlite3_str_errcode_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_str_length", drb_ffi_sqlite3_str_length_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_str_value", drb_ffi_sqlite3_str_value_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_status", drb_ffi_sqlite3_status_Binding, MRB_ARGS_REQ(4));
    drb_api->mrb_define_module_function(state, module, "sqlite3_status64", drb_ffi_sqlite3_status64_Binding, MRB_ARGS_REQ(4));
    drb_api->mrb_define_module_function(state, module, "sqlite3_db_status", drb_ffi_sqlite3_db_status_Binding, MRB_ARGS_REQ(5));
    drb_api->mrb_define_module_function(state, module, "sqlite3_stmt_status", drb_ffi_sqlite3_stmt_status_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "sqlite3_backup_init", drb_ffi_sqlite3_backup_init_Binding, MRB_ARGS_REQ(4));
    drb_api->mrb_define_module_function(state, module, "sqlite3_backup_step", drb_ffi_sqlite3_backup_step_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_backup_finish", drb_ffi_sqlite3_backup_finish_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_backup_remaining", drb_ffi_sqlite3_backup_remaining_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_backup_pagecount", drb_ffi_sqlite3_backup_pagecount_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_stricmp", drb_ffi_sqlite3_stricmp_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_strnicmp", drb_ffi_sqlite3_strnicmp_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "sqlite3_strglob", drb_ffi_sqlite3_strglob_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_strlike", drb_ffi_sqlite3_strlike_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "sqlite3_wal_hook", drb_ffi_sqlite3_wal_hook_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "sqlite3_wal_autocheckpoint", drb_ffi_sqlite3_wal_autocheckpoint_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_wal_checkpoint", drb_ffi_sqlite3_wal_checkpoint_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_wal_checkpoint_v2", drb_ffi_sqlite3_wal_checkpoint_v2_Binding, MRB_ARGS_REQ(5));
    drb_api->mrb_define_module_function(state, module, "sqlite3_vtab_on_conflict", drb_ffi_sqlite3_vtab_on_conflict_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_vtab_nochange", drb_ffi_sqlite3_vtab_nochange_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_vtab_collation", drb_ffi_sqlite3_vtab_collation_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_vtab_distinct", drb_ffi_sqlite3_vtab_distinct_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_vtab_in", drb_ffi_sqlite3_vtab_in_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "sqlite3_vtab_in_first", drb_ffi_sqlite3_vtab_in_first_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_vtab_in_next", drb_ffi_sqlite3_vtab_in_next_Binding, MRB_ARGS_REQ(2));
    drb_api->mrb_define_module_function(state, module, "sqlite3_vtab_rhs_value", drb_ffi_sqlite3_vtab_rhs_value_Binding, MRB_ARGS_REQ(3));
    drb_api->mrb_define_module_function(state, module, "sqlite3_db_cacheflush", drb_ffi_sqlite3_db_cacheflush_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_system_errno", drb_ffi_sqlite3_system_errno_Binding, MRB_ARGS_REQ(1));
    drb_api->mrb_define_module_function(state, module, "sqlite3_serialize", drb_ffi_sqlite3_serialize_Binding, MRB_ARGS_REQ(4));
    drb_api->mrb_define_module_function(state, module, "sqlite3_deserialize", drb_ffi_sqlite3_deserialize_Binding, MRB_ARGS_REQ(6));
    drb_api->mrb_define_module_function(state, module, "sqlite3_rtree_geometry_callback", drb_ffi_sqlite3_rtree_geometry_callback_Binding, MRB_ARGS_REQ(4));
    drb_api->mrb_define_module_function(state, module, "sqlite3_rtree_query_callback", drb_ffi_sqlite3_rtree_query_callback_Binding, MRB_ARGS_REQ(5));
    struct RClass *CharPointerClass = drb_api->mrb_define_class_under(state, module, "CharPointer", object_class);
    drb_api->mrb_define_class_method(state, CharPointerClass, "new", drb_ffi__ZTSPc_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, CharPointerClass, "value", drb_ffi__ZTSPc_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, CharPointerClass, "[]", drb_ffi__ZTSPc_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, CharPointerClass, "[]=", drb_ffi__ZTSPc_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, CharPointerClass, "nil?", drb_ffi__ZTSPc_IsNil, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, CharPointerClass, "str", drb_ffi__ZTSPc_GetString, MRB_ARGS_REQ(0));
    struct RClass *Sqlite3PointerClass = drb_api->mrb_define_class_under(state, module, "Sqlite3Pointer", object_class);
    drb_api->mrb_define_class_method(state, Sqlite3PointerClass, "new", drb_ffi__ZTSP7sqlite3_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3PointerClass, "value", drb_ffi__ZTSP7sqlite3_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3PointerClass, "[]", drb_ffi__ZTSP7sqlite3_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3PointerClass, "[]=", drb_ffi__ZTSP7sqlite3_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Sqlite3PointerClass, "nil?", drb_ffi__ZTSP7sqlite3_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_0PointerClass = drb_api->mrb_define_class_under(state, module, "Function_0Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_0PointerClass, "new", drb_ffi__ZTSPFiPviPPcS1_E_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_0PointerClass, "value", drb_ffi__ZTSPFiPviPPcS1_E_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_0PointerClass, "[]", drb_ffi__ZTSPFiPviPPcS1_E_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_0PointerClass, "[]=", drb_ffi__ZTSPFiPviPPcS1_E_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_0PointerClass, "nil?", drb_ffi__ZTSPFiPviPPcS1_E_IsNil, MRB_ARGS_REQ(0));
    struct RClass *VoidPointerClass = drb_api->mrb_define_class_under(state, module, "VoidPointer", object_class);
    struct RClass *CharPointerPointerClass = drb_api->mrb_define_class_under(state, module, "CharPointerPointer", object_class);
    drb_api->mrb_define_class_method(state, CharPointerPointerClass, "new", drb_ffi__ZTSPPc_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, CharPointerPointerClass, "value", drb_ffi__ZTSPPc_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, CharPointerPointerClass, "[]", drb_ffi__ZTSPPc_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, CharPointerPointerClass, "[]=", drb_ffi__ZTSPPc_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, CharPointerPointerClass, "nil?", drb_ffi__ZTSPPc_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_1PointerClass = drb_api->mrb_define_class_under(state, module, "Function_1Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_1PointerClass, "new", drb_ffi__ZTSPFiPviE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_1PointerClass, "value", drb_ffi__ZTSPFiPviE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_1PointerClass, "[]", drb_ffi__ZTSPFiPviE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_1PointerClass, "[]=", drb_ffi__ZTSPFiPviE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_1PointerClass, "nil?", drb_ffi__ZTSPFiPviE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *CharPointerPointerPointerClass = drb_api->mrb_define_class_under(state, module, "CharPointerPointerPointer", object_class);
    drb_api->mrb_define_class_method(state, CharPointerPointerPointerClass, "new", drb_ffi__ZTSPPPc_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, CharPointerPointerPointerClass, "value", drb_ffi__ZTSPPPc_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, CharPointerPointerPointerClass, "[]", drb_ffi__ZTSPPPc_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, CharPointerPointerPointerClass, "[]=", drb_ffi__ZTSPPPc_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, CharPointerPointerPointerClass, "nil?", drb_ffi__ZTSPPPc_IsNil, MRB_ARGS_REQ(0));
    struct RClass *IntPointerClass = drb_api->mrb_define_class_under(state, module, "IntPointer", object_class);
    drb_api->mrb_define_class_method(state, IntPointerClass, "new", drb_ffi__ZTSPi_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, IntPointerClass, "value", drb_ffi__ZTSPi_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, IntPointerClass, "[]", drb_ffi__ZTSPi_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, IntPointerClass, "[]=", drb_ffi__ZTSPi_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, IntPointerClass, "nil?", drb_ffi__ZTSPi_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_2PointerClass = drb_api->mrb_define_class_under(state, module, "Function_2Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_2PointerClass, "new", drb_ffi__ZTSPFiPviPKcS1_S1_S1_E_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_2PointerClass, "value", drb_ffi__ZTSPFiPviPKcS1_S1_S1_E_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_2PointerClass, "[]", drb_ffi__ZTSPFiPviPKcS1_S1_S1_E_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_2PointerClass, "[]=", drb_ffi__ZTSPFiPviPKcS1_S1_S1_E_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_2PointerClass, "nil?", drb_ffi__ZTSPFiPviPKcS1_S1_S1_E_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_3PointerClass = drb_api->mrb_define_class_under(state, module, "Function_3Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_3PointerClass, "new", drb_ffi__ZTSPFvPvPKcE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_3PointerClass, "value", drb_ffi__ZTSPFvPvPKcE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_3PointerClass, "[]", drb_ffi__ZTSPFvPvPKcE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_3PointerClass, "[]=", drb_ffi__ZTSPFvPvPKcE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_3PointerClass, "nil?", drb_ffi__ZTSPFvPvPKcE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_4PointerClass = drb_api->mrb_define_class_under(state, module, "Function_4Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_4PointerClass, "new", drb_ffi__ZTSPFvPvPKcyE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_4PointerClass, "value", drb_ffi__ZTSPFvPvPKcyE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_4PointerClass, "[]", drb_ffi__ZTSPFvPvPKcyE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_4PointerClass, "[]=", drb_ffi__ZTSPFvPvPKcyE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_4PointerClass, "nil?", drb_ffi__ZTSPFvPvPKcyE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_5PointerClass = drb_api->mrb_define_class_under(state, module, "Function_5Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_5PointerClass, "new", drb_ffi__ZTSPFijPvS_S_E_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_5PointerClass, "value", drb_ffi__ZTSPFijPvS_S_E_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_5PointerClass, "[]", drb_ffi__ZTSPFijPvS_S_E_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_5PointerClass, "[]=", drb_ffi__ZTSPFijPvS_S_E_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_5PointerClass, "nil?", drb_ffi__ZTSPFijPvS_S_E_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_6PointerClass = drb_api->mrb_define_class_under(state, module, "Function_6Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_6PointerClass, "new", drb_ffi__ZTSPFiPvE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_6PointerClass, "value", drb_ffi__ZTSPFiPvE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_6PointerClass, "[]", drb_ffi__ZTSPFiPvE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_6PointerClass, "[]=", drb_ffi__ZTSPFiPvE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_6PointerClass, "nil?", drb_ffi__ZTSPFiPvE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Sqlite3PointerPointerClass = drb_api->mrb_define_class_under(state, module, "Sqlite3PointerPointer", object_class);
    drb_api->mrb_define_class_method(state, Sqlite3PointerPointerClass, "new", drb_ffi__ZTSPP7sqlite3_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3PointerPointerClass, "value", drb_ffi__ZTSPP7sqlite3_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3PointerPointerClass, "[]", drb_ffi__ZTSPP7sqlite3_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3PointerPointerClass, "[]=", drb_ffi__ZTSPP7sqlite3_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Sqlite3PointerPointerClass, "nil?", drb_ffi__ZTSPP7sqlite3_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Sqlite3_filePointerClass = drb_api->mrb_define_class_under(state, module, "Sqlite3_filePointer", object_class);
    drb_api->mrb_define_class_method(state, Sqlite3_filePointerClass, "new", drb_ffi__ZTSP12sqlite3_file_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_filePointerClass, "value", drb_ffi__ZTSP12sqlite3_file_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_filePointerClass, "[]", drb_ffi__ZTSP12sqlite3_file_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_filePointerClass, "[]=", drb_ffi__ZTSP12sqlite3_file_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Sqlite3_filePointerClass, "nil?", drb_ffi__ZTSP12sqlite3_file_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Sqlite3_stmtPointerPointerClass = drb_api->mrb_define_class_under(state, module, "Sqlite3_stmtPointerPointer", object_class);
    drb_api->mrb_define_class_method(state, Sqlite3_stmtPointerPointerClass, "new", drb_ffi__ZTSPP12sqlite3_stmt_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_stmtPointerPointerClass, "value", drb_ffi__ZTSPP12sqlite3_stmt_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_stmtPointerPointerClass, "[]", drb_ffi__ZTSPP12sqlite3_stmt_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_stmtPointerPointerClass, "[]=", drb_ffi__ZTSPP12sqlite3_stmt_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Sqlite3_stmtPointerPointerClass, "nil?", drb_ffi__ZTSPP12sqlite3_stmt_IsNil, MRB_ARGS_REQ(0));
    struct RClass *VoidPointerPointerClass = drb_api->mrb_define_class_under(state, module, "VoidPointerPointer", object_class);
    drb_api->mrb_define_class_method(state, VoidPointerPointerClass, "new", drb_ffi__ZTSPPv_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, VoidPointerPointerClass, "value", drb_ffi__ZTSPPv_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, VoidPointerPointerClass, "[]", drb_ffi__ZTSPPv_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, VoidPointerPointerClass, "[]=", drb_ffi__ZTSPPv_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, VoidPointerPointerClass, "nil?", drb_ffi__ZTSPPv_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Sqlite3_stmtPointerClass = drb_api->mrb_define_class_under(state, module, "Sqlite3_stmtPointer", object_class);
    drb_api->mrb_define_class_method(state, Sqlite3_stmtPointerClass, "new", drb_ffi__ZTSP12sqlite3_stmt_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_stmtPointerClass, "value", drb_ffi__ZTSP12sqlite3_stmt_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_stmtPointerClass, "[]", drb_ffi__ZTSP12sqlite3_stmt_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_stmtPointerClass, "[]=", drb_ffi__ZTSP12sqlite3_stmt_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Sqlite3_stmtPointerClass, "nil?", drb_ffi__ZTSP12sqlite3_stmt_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_7PointerClass = drb_api->mrb_define_class_under(state, module, "Function_7Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_7PointerClass, "new", drb_ffi__ZTSPFvPvE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_7PointerClass, "value", drb_ffi__ZTSPFvPvE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_7PointerClass, "[]", drb_ffi__ZTSPFvPvE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_7PointerClass, "[]=", drb_ffi__ZTSPFvPvE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_7PointerClass, "nil?", drb_ffi__ZTSPFvPvE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Sqlite3_valuePointerClass = drb_api->mrb_define_class_under(state, module, "Sqlite3_valuePointer", object_class);
    drb_api->mrb_define_class_method(state, Sqlite3_valuePointerClass, "new", drb_ffi__ZTSP13sqlite3_value_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_valuePointerClass, "value", drb_ffi__ZTSP13sqlite3_value_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_valuePointerClass, "[]", drb_ffi__ZTSP13sqlite3_value_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_valuePointerClass, "[]=", drb_ffi__ZTSP13sqlite3_value_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Sqlite3_valuePointerClass, "nil?", drb_ffi__ZTSP13sqlite3_value_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Unsigned_charPointerClass = drb_api->mrb_define_class_under(state, module, "Unsigned_charPointer", object_class);
    drb_api->mrb_define_class_method(state, Unsigned_charPointerClass, "new", drb_ffi__ZTSPh_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Unsigned_charPointerClass, "value", drb_ffi__ZTSPh_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Unsigned_charPointerClass, "[]", drb_ffi__ZTSPh_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Unsigned_charPointerClass, "[]=", drb_ffi__ZTSPh_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Unsigned_charPointerClass, "nil?", drb_ffi__ZTSPh_IsNil, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Unsigned_charPointerClass, "str", drb_ffi__ZTSPh_GetString, MRB_ARGS_REQ(0));
    struct RClass *Function_8PointerClass = drb_api->mrb_define_class_under(state, module, "Function_8Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_8PointerClass, "new", drb_ffi__ZTSPFvP15sqlite3_contextiPP13sqlite3_valueE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_8PointerClass, "value", drb_ffi__ZTSPFvP15sqlite3_contextiPP13sqlite3_valueE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_8PointerClass, "[]", drb_ffi__ZTSPFvP15sqlite3_contextiPP13sqlite3_valueE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_8PointerClass, "[]=", drb_ffi__ZTSPFvP15sqlite3_contextiPP13sqlite3_valueE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_8PointerClass, "nil?", drb_ffi__ZTSPFvP15sqlite3_contextiPP13sqlite3_valueE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_9PointerClass = drb_api->mrb_define_class_under(state, module, "Function_9Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_9PointerClass, "new", drb_ffi__ZTSPFvP15sqlite3_contextE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_9PointerClass, "value", drb_ffi__ZTSPFvP15sqlite3_contextE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_9PointerClass, "[]", drb_ffi__ZTSPFvP15sqlite3_contextE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_9PointerClass, "[]=", drb_ffi__ZTSPFvP15sqlite3_contextE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_9PointerClass, "nil?", drb_ffi__ZTSPFvP15sqlite3_contextE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Sqlite3_contextPointerClass = drb_api->mrb_define_class_under(state, module, "Sqlite3_contextPointer", object_class);
    drb_api->mrb_define_class_method(state, Sqlite3_contextPointerClass, "new", drb_ffi__ZTSP15sqlite3_context_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_contextPointerClass, "value", drb_ffi__ZTSP15sqlite3_context_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_contextPointerClass, "[]", drb_ffi__ZTSP15sqlite3_context_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_contextPointerClass, "[]=", drb_ffi__ZTSP15sqlite3_context_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Sqlite3_contextPointerClass, "nil?", drb_ffi__ZTSP15sqlite3_context_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_10PointerClass = drb_api->mrb_define_class_under(state, module, "Function_10Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_10PointerClass, "new", drb_ffi__ZTSPFvPvxiE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_10PointerClass, "value", drb_ffi__ZTSPFvPvxiE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_10PointerClass, "[]", drb_ffi__ZTSPFvPvxiE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_10PointerClass, "[]=", drb_ffi__ZTSPFvPvxiE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_10PointerClass, "nil?", drb_ffi__ZTSPFvPvxiE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_11PointerClass = drb_api->mrb_define_class_under(state, module, "Function_11Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_11PointerClass, "new", drb_ffi__ZTSPFiPviPKviS1_E_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_11PointerClass, "value", drb_ffi__ZTSPFiPviPKviS1_E_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_11PointerClass, "[]", drb_ffi__ZTSPFiPviPKviS1_E_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_11PointerClass, "[]=", drb_ffi__ZTSPFiPviPKviS1_E_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_11PointerClass, "nil?", drb_ffi__ZTSPFiPviPKviS1_E_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_12PointerClass = drb_api->mrb_define_class_under(state, module, "Function_12Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_12PointerClass, "new", drb_ffi__ZTSPFvPvP7sqlite3iPKcE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_12PointerClass, "value", drb_ffi__ZTSPFvPvP7sqlite3iPKcE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_12PointerClass, "[]", drb_ffi__ZTSPFvPvP7sqlite3iPKcE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_12PointerClass, "[]=", drb_ffi__ZTSPFvPvP7sqlite3iPKcE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_12PointerClass, "nil?", drb_ffi__ZTSPFvPvP7sqlite3iPKcE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_13PointerClass = drb_api->mrb_define_class_under(state, module, "Function_13Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_13PointerClass, "new", drb_ffi__ZTSPFvPvP7sqlite3iPKvE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_13PointerClass, "value", drb_ffi__ZTSPFvPvP7sqlite3iPKvE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_13PointerClass, "[]", drb_ffi__ZTSPFvPvP7sqlite3iPKvE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_13PointerClass, "[]=", drb_ffi__ZTSPFvPvP7sqlite3iPKvE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_13PointerClass, "nil?", drb_ffi__ZTSPFvPvP7sqlite3iPKvE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_14PointerClass = drb_api->mrb_define_class_under(state, module, "Function_14Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_14PointerClass, "new", drb_ffi__ZTSPFjPvPKcjjjE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_14PointerClass, "value", drb_ffi__ZTSPFjPvPKcjjjE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_14PointerClass, "[]", drb_ffi__ZTSPFjPvPKcjjjE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_14PointerClass, "[]=", drb_ffi__ZTSPFjPvPKcjjjE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_14PointerClass, "nil?", drb_ffi__ZTSPFjPvPKcjjjE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_15PointerClass = drb_api->mrb_define_class_under(state, module, "Function_15Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_15PointerClass, "new", drb_ffi__ZTSPFvPviPKcS1_xE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_15PointerClass, "value", drb_ffi__ZTSPFvPviPKcS1_xE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_15PointerClass, "[]", drb_ffi__ZTSPFvPviPKcS1_xE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_15PointerClass, "[]=", drb_ffi__ZTSPFvPviPKcS1_xE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_15PointerClass, "nil?", drb_ffi__ZTSPFvPviPKcS1_xE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_16PointerClass = drb_api->mrb_define_class_under(state, module, "Function_16Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_16PointerClass, "new", drb_ffi__ZTSPFvvE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_16PointerClass, "value", drb_ffi__ZTSPFvvE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_16PointerClass, "[]", drb_ffi__ZTSPFvvE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_16PointerClass, "[]=", drb_ffi__ZTSPFvvE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_16PointerClass, "nil?", drb_ffi__ZTSPFvvE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Sqlite3_modulePointerClass = drb_api->mrb_define_class_under(state, module, "Sqlite3_modulePointer", object_class);
    drb_api->mrb_define_class_method(state, Sqlite3_modulePointerClass, "new", drb_ffi__ZTSP14sqlite3_module_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_modulePointerClass, "value", drb_ffi__ZTSP14sqlite3_module_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_modulePointerClass, "[]", drb_ffi__ZTSP14sqlite3_module_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_modulePointerClass, "[]=", drb_ffi__ZTSP14sqlite3_module_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Sqlite3_modulePointerClass, "nil?", drb_ffi__ZTSP14sqlite3_module_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Sqlite3_blobPointerPointerClass = drb_api->mrb_define_class_under(state, module, "Sqlite3_blobPointerPointer", object_class);
    drb_api->mrb_define_class_method(state, Sqlite3_blobPointerPointerClass, "new", drb_ffi__ZTSPP12sqlite3_blob_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_blobPointerPointerClass, "value", drb_ffi__ZTSPP12sqlite3_blob_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_blobPointerPointerClass, "[]", drb_ffi__ZTSPP12sqlite3_blob_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_blobPointerPointerClass, "[]=", drb_ffi__ZTSPP12sqlite3_blob_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Sqlite3_blobPointerPointerClass, "nil?", drb_ffi__ZTSPP12sqlite3_blob_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Sqlite3_blobPointerClass = drb_api->mrb_define_class_under(state, module, "Sqlite3_blobPointer", object_class);
    drb_api->mrb_define_class_method(state, Sqlite3_blobPointerClass, "new", drb_ffi__ZTSP12sqlite3_blob_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_blobPointerClass, "value", drb_ffi__ZTSP12sqlite3_blob_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_blobPointerClass, "[]", drb_ffi__ZTSP12sqlite3_blob_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_blobPointerClass, "[]=", drb_ffi__ZTSP12sqlite3_blob_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Sqlite3_blobPointerClass, "nil?", drb_ffi__ZTSP12sqlite3_blob_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Sqlite3_vfsPointerClass = drb_api->mrb_define_class_under(state, module, "Sqlite3_vfsPointer", object_class);
    drb_api->mrb_define_class_method(state, Sqlite3_vfsPointerClass, "new", drb_ffi__ZTSP11sqlite3_vfs_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_vfsPointerClass, "value", drb_ffi__ZTSP11sqlite3_vfs_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_vfsPointerClass, "[]", drb_ffi__ZTSP11sqlite3_vfs_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_vfsPointerClass, "[]=", drb_ffi__ZTSP11sqlite3_vfs_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Sqlite3_vfsPointerClass, "nil?", drb_ffi__ZTSP11sqlite3_vfs_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Sqlite3_mutexPointerClass = drb_api->mrb_define_class_under(state, module, "Sqlite3_mutexPointer", object_class);
    drb_api->mrb_define_class_method(state, Sqlite3_mutexPointerClass, "new", drb_ffi__ZTSP13sqlite3_mutex_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_mutexPointerClass, "value", drb_ffi__ZTSP13sqlite3_mutex_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_mutexPointerClass, "[]", drb_ffi__ZTSP13sqlite3_mutex_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_mutexPointerClass, "[]=", drb_ffi__ZTSP13sqlite3_mutex_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Sqlite3_mutexPointerClass, "nil?", drb_ffi__ZTSP13sqlite3_mutex_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Sqlite3_strPointerClass = drb_api->mrb_define_class_under(state, module, "Sqlite3_strPointer", object_class);
    drb_api->mrb_define_class_method(state, Sqlite3_strPointerClass, "new", drb_ffi__ZTSP11sqlite3_str_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_strPointerClass, "value", drb_ffi__ZTSP11sqlite3_str_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_strPointerClass, "[]", drb_ffi__ZTSP11sqlite3_str_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_strPointerClass, "[]=", drb_ffi__ZTSP11sqlite3_str_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Sqlite3_strPointerClass, "nil?", drb_ffi__ZTSP11sqlite3_str_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Long_longPointerClass = drb_api->mrb_define_class_under(state, module, "Long_longPointer", object_class);
    drb_api->mrb_define_class_method(state, Long_longPointerClass, "new", drb_ffi__ZTSPx_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Long_longPointerClass, "value", drb_ffi__ZTSPx_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Long_longPointerClass, "[]", drb_ffi__ZTSPx_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Long_longPointerClass, "[]=", drb_ffi__ZTSPx_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Long_longPointerClass, "nil?", drb_ffi__ZTSPx_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Sqlite3_backupPointerClass = drb_api->mrb_define_class_under(state, module, "Sqlite3_backupPointer", object_class);
    drb_api->mrb_define_class_method(state, Sqlite3_backupPointerClass, "new", drb_ffi__ZTSP14sqlite3_backup_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_backupPointerClass, "value", drb_ffi__ZTSP14sqlite3_backup_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_backupPointerClass, "[]", drb_ffi__ZTSP14sqlite3_backup_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_backupPointerClass, "[]=", drb_ffi__ZTSP14sqlite3_backup_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Sqlite3_backupPointerClass, "nil?", drb_ffi__ZTSP14sqlite3_backup_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_17PointerClass = drb_api->mrb_define_class_under(state, module, "Function_17Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_17PointerClass, "new", drb_ffi__ZTSPFiPvP7sqlite3PKciE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_17PointerClass, "value", drb_ffi__ZTSPFiPvP7sqlite3PKciE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_17PointerClass, "[]", drb_ffi__ZTSPFiPvP7sqlite3PKciE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_17PointerClass, "[]=", drb_ffi__ZTSPFiPvP7sqlite3PKciE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_17PointerClass, "nil?", drb_ffi__ZTSPFiPvP7sqlite3PKciE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Sqlite3_index_infoPointerClass = drb_api->mrb_define_class_under(state, module, "Sqlite3_index_infoPointer", object_class);
    drb_api->mrb_define_class_method(state, Sqlite3_index_infoPointerClass, "new", drb_ffi__ZTSP18sqlite3_index_info_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_index_infoPointerClass, "value", drb_ffi__ZTSP18sqlite3_index_info_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_index_infoPointerClass, "[]", drb_ffi__ZTSP18sqlite3_index_info_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_index_infoPointerClass, "[]=", drb_ffi__ZTSP18sqlite3_index_info_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Sqlite3_index_infoPointerClass, "nil?", drb_ffi__ZTSP18sqlite3_index_info_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Sqlite3_valuePointerPointerClass = drb_api->mrb_define_class_under(state, module, "Sqlite3_valuePointerPointer", object_class);
    drb_api->mrb_define_class_method(state, Sqlite3_valuePointerPointerClass, "new", drb_ffi__ZTSPP13sqlite3_value_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_valuePointerPointerClass, "value", drb_ffi__ZTSPP13sqlite3_value_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_valuePointerPointerClass, "[]", drb_ffi__ZTSPP13sqlite3_value_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_valuePointerPointerClass, "[]=", drb_ffi__ZTSPP13sqlite3_value_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Sqlite3_valuePointerPointerClass, "nil?", drb_ffi__ZTSPP13sqlite3_value_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_18PointerClass = drb_api->mrb_define_class_under(state, module, "Function_18Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_18PointerClass, "new", drb_ffi__ZTSPFiP22sqlite3_rtree_geometryiPdPiE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_18PointerClass, "value", drb_ffi__ZTSPFiP22sqlite3_rtree_geometryiPdPiE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_18PointerClass, "[]", drb_ffi__ZTSPFiP22sqlite3_rtree_geometryiPdPiE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_18PointerClass, "[]=", drb_ffi__ZTSPFiP22sqlite3_rtree_geometryiPdPiE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_18PointerClass, "nil?", drb_ffi__ZTSPFiP22sqlite3_rtree_geometryiPdPiE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_19PointerClass = drb_api->mrb_define_class_under(state, module, "Function_19Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_19PointerClass, "new", drb_ffi__ZTSPFiP24sqlite3_rtree_query_infoE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_19PointerClass, "value", drb_ffi__ZTSPFiP24sqlite3_rtree_query_infoE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_19PointerClass, "[]", drb_ffi__ZTSPFiP24sqlite3_rtree_query_infoE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_19PointerClass, "[]=", drb_ffi__ZTSPFiP24sqlite3_rtree_query_infoE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_19PointerClass, "nil?", drb_ffi__ZTSPFiP24sqlite3_rtree_query_infoE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Sqlite3_io_methodsPointerClass = drb_api->mrb_define_class_under(state, module, "Sqlite3_io_methodsPointer", object_class);
    drb_api->mrb_define_class_method(state, Sqlite3_io_methodsPointerClass, "new", drb_ffi__ZTSP18sqlite3_io_methods_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_io_methodsPointerClass, "value", drb_ffi__ZTSP18sqlite3_io_methods_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_io_methodsPointerClass, "[]", drb_ffi__ZTSP18sqlite3_io_methods_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_io_methodsPointerClass, "[]=", drb_ffi__ZTSP18sqlite3_io_methods_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Sqlite3_io_methodsPointerClass, "nil?", drb_ffi__ZTSP18sqlite3_io_methods_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_20PointerClass = drb_api->mrb_define_class_under(state, module, "Function_20Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_20PointerClass, "new", drb_ffi__ZTSPFiP7sqlite3PviPKPKcPP12sqlite3_vtabPPcE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_20PointerClass, "value", drb_ffi__ZTSPFiP7sqlite3PviPKPKcPP12sqlite3_vtabPPcE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_20PointerClass, "[]", drb_ffi__ZTSPFiP7sqlite3PviPKPKcPP12sqlite3_vtabPPcE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_20PointerClass, "[]=", drb_ffi__ZTSPFiP7sqlite3PviPKPKcPP12sqlite3_vtabPPcE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_20PointerClass, "nil?", drb_ffi__ZTSPFiP7sqlite3PviPKPKcPP12sqlite3_vtabPPcE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_21PointerClass = drb_api->mrb_define_class_under(state, module, "Function_21Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_21PointerClass, "new", drb_ffi__ZTSPFiP12sqlite3_vtabP18sqlite3_index_infoE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_21PointerClass, "value", drb_ffi__ZTSPFiP12sqlite3_vtabP18sqlite3_index_infoE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_21PointerClass, "[]", drb_ffi__ZTSPFiP12sqlite3_vtabP18sqlite3_index_infoE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_21PointerClass, "[]=", drb_ffi__ZTSPFiP12sqlite3_vtabP18sqlite3_index_infoE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_21PointerClass, "nil?", drb_ffi__ZTSPFiP12sqlite3_vtabP18sqlite3_index_infoE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_22PointerClass = drb_api->mrb_define_class_under(state, module, "Function_22Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_22PointerClass, "new", drb_ffi__ZTSPFiP12sqlite3_vtabE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_22PointerClass, "value", drb_ffi__ZTSPFiP12sqlite3_vtabE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_22PointerClass, "[]", drb_ffi__ZTSPFiP12sqlite3_vtabE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_22PointerClass, "[]=", drb_ffi__ZTSPFiP12sqlite3_vtabE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_22PointerClass, "nil?", drb_ffi__ZTSPFiP12sqlite3_vtabE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_23PointerClass = drb_api->mrb_define_class_under(state, module, "Function_23Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_23PointerClass, "new", drb_ffi__ZTSPFiP12sqlite3_vtabPP19sqlite3_vtab_cursorE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_23PointerClass, "value", drb_ffi__ZTSPFiP12sqlite3_vtabPP19sqlite3_vtab_cursorE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_23PointerClass, "[]", drb_ffi__ZTSPFiP12sqlite3_vtabPP19sqlite3_vtab_cursorE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_23PointerClass, "[]=", drb_ffi__ZTSPFiP12sqlite3_vtabPP19sqlite3_vtab_cursorE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_23PointerClass, "nil?", drb_ffi__ZTSPFiP12sqlite3_vtabPP19sqlite3_vtab_cursorE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_24PointerClass = drb_api->mrb_define_class_under(state, module, "Function_24Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_24PointerClass, "new", drb_ffi__ZTSPFiP19sqlite3_vtab_cursorE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_24PointerClass, "value", drb_ffi__ZTSPFiP19sqlite3_vtab_cursorE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_24PointerClass, "[]", drb_ffi__ZTSPFiP19sqlite3_vtab_cursorE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_24PointerClass, "[]=", drb_ffi__ZTSPFiP19sqlite3_vtab_cursorE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_24PointerClass, "nil?", drb_ffi__ZTSPFiP19sqlite3_vtab_cursorE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_25PointerClass = drb_api->mrb_define_class_under(state, module, "Function_25Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_25PointerClass, "new", drb_ffi__ZTSPFiP19sqlite3_vtab_cursoriPKciPP13sqlite3_valueE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_25PointerClass, "value", drb_ffi__ZTSPFiP19sqlite3_vtab_cursoriPKciPP13sqlite3_valueE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_25PointerClass, "[]", drb_ffi__ZTSPFiP19sqlite3_vtab_cursoriPKciPP13sqlite3_valueE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_25PointerClass, "[]=", drb_ffi__ZTSPFiP19sqlite3_vtab_cursoriPKciPP13sqlite3_valueE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_25PointerClass, "nil?", drb_ffi__ZTSPFiP19sqlite3_vtab_cursoriPKciPP13sqlite3_valueE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_26PointerClass = drb_api->mrb_define_class_under(state, module, "Function_26Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_26PointerClass, "new", drb_ffi__ZTSPFiP19sqlite3_vtab_cursorP15sqlite3_contextiE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_26PointerClass, "value", drb_ffi__ZTSPFiP19sqlite3_vtab_cursorP15sqlite3_contextiE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_26PointerClass, "[]", drb_ffi__ZTSPFiP19sqlite3_vtab_cursorP15sqlite3_contextiE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_26PointerClass, "[]=", drb_ffi__ZTSPFiP19sqlite3_vtab_cursorP15sqlite3_contextiE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_26PointerClass, "nil?", drb_ffi__ZTSPFiP19sqlite3_vtab_cursorP15sqlite3_contextiE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_27PointerClass = drb_api->mrb_define_class_under(state, module, "Function_27Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_27PointerClass, "new", drb_ffi__ZTSPFiP19sqlite3_vtab_cursorPxE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_27PointerClass, "value", drb_ffi__ZTSPFiP19sqlite3_vtab_cursorPxE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_27PointerClass, "[]", drb_ffi__ZTSPFiP19sqlite3_vtab_cursorPxE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_27PointerClass, "[]=", drb_ffi__ZTSPFiP19sqlite3_vtab_cursorPxE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_27PointerClass, "nil?", drb_ffi__ZTSPFiP19sqlite3_vtab_cursorPxE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_28PointerClass = drb_api->mrb_define_class_under(state, module, "Function_28Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_28PointerClass, "new", drb_ffi__ZTSPFiP12sqlite3_vtabiPP13sqlite3_valuePxE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_28PointerClass, "value", drb_ffi__ZTSPFiP12sqlite3_vtabiPP13sqlite3_valuePxE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_28PointerClass, "[]", drb_ffi__ZTSPFiP12sqlite3_vtabiPP13sqlite3_valuePxE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_28PointerClass, "[]=", drb_ffi__ZTSPFiP12sqlite3_vtabiPP13sqlite3_valuePxE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_28PointerClass, "nil?", drb_ffi__ZTSPFiP12sqlite3_vtabiPP13sqlite3_valuePxE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_29PointerClass = drb_api->mrb_define_class_under(state, module, "Function_29Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_29PointerClass, "new", drb_ffi__ZTSPFiP12sqlite3_vtabiPKcPPFvP15sqlite3_contextiPP13sqlite3_valueEPPvE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_29PointerClass, "value", drb_ffi__ZTSPFiP12sqlite3_vtabiPKcPPFvP15sqlite3_contextiPP13sqlite3_valueEPPvE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_29PointerClass, "[]", drb_ffi__ZTSPFiP12sqlite3_vtabiPKcPPFvP15sqlite3_contextiPP13sqlite3_valueEPPvE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_29PointerClass, "[]=", drb_ffi__ZTSPFiP12sqlite3_vtabiPKcPPFvP15sqlite3_contextiPP13sqlite3_valueEPPvE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_29PointerClass, "nil?", drb_ffi__ZTSPFiP12sqlite3_vtabiPKcPPFvP15sqlite3_contextiPP13sqlite3_valueEPPvE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_30PointerClass = drb_api->mrb_define_class_under(state, module, "Function_30Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_30PointerClass, "new", drb_ffi__ZTSPFiP12sqlite3_vtabPKcE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_30PointerClass, "value", drb_ffi__ZTSPFiP12sqlite3_vtabPKcE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_30PointerClass, "[]", drb_ffi__ZTSPFiP12sqlite3_vtabPKcE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_30PointerClass, "[]=", drb_ffi__ZTSPFiP12sqlite3_vtabPKcE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_30PointerClass, "nil?", drb_ffi__ZTSPFiP12sqlite3_vtabPKcE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_31PointerClass = drb_api->mrb_define_class_under(state, module, "Function_31Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_31PointerClass, "new", drb_ffi__ZTSPFiP12sqlite3_vtabiE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_31PointerClass, "value", drb_ffi__ZTSPFiP12sqlite3_vtabiE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_31PointerClass, "[]", drb_ffi__ZTSPFiP12sqlite3_vtabiE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_31PointerClass, "[]=", drb_ffi__ZTSPFiP12sqlite3_vtabiE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_31PointerClass, "nil?", drb_ffi__ZTSPFiP12sqlite3_vtabiE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_32PointerClass = drb_api->mrb_define_class_under(state, module, "Function_32Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_32PointerClass, "new", drb_ffi__ZTSPFiPKcE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_32PointerClass, "value", drb_ffi__ZTSPFiPKcE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_32PointerClass, "[]", drb_ffi__ZTSPFiPKcE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_32PointerClass, "[]=", drb_ffi__ZTSPFiPKcE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_32PointerClass, "nil?", drb_ffi__ZTSPFiPKcE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_33PointerClass = drb_api->mrb_define_class_under(state, module, "Function_33Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_33PointerClass, "new", drb_ffi__ZTSPFiP11sqlite3_vfsPKcP12sqlite3_fileiPiE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_33PointerClass, "value", drb_ffi__ZTSPFiP11sqlite3_vfsPKcP12sqlite3_fileiPiE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_33PointerClass, "[]", drb_ffi__ZTSPFiP11sqlite3_vfsPKcP12sqlite3_fileiPiE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_33PointerClass, "[]=", drb_ffi__ZTSPFiP11sqlite3_vfsPKcP12sqlite3_fileiPiE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_33PointerClass, "nil?", drb_ffi__ZTSPFiP11sqlite3_vfsPKcP12sqlite3_fileiPiE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_34PointerClass = drb_api->mrb_define_class_under(state, module, "Function_34Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_34PointerClass, "new", drb_ffi__ZTSPFiP11sqlite3_vfsPKciE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_34PointerClass, "value", drb_ffi__ZTSPFiP11sqlite3_vfsPKciE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_34PointerClass, "[]", drb_ffi__ZTSPFiP11sqlite3_vfsPKciE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_34PointerClass, "[]=", drb_ffi__ZTSPFiP11sqlite3_vfsPKciE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_34PointerClass, "nil?", drb_ffi__ZTSPFiP11sqlite3_vfsPKciE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_35PointerClass = drb_api->mrb_define_class_under(state, module, "Function_35Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_35PointerClass, "new", drb_ffi__ZTSPFiP11sqlite3_vfsPKciPiE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_35PointerClass, "value", drb_ffi__ZTSPFiP11sqlite3_vfsPKciPiE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_35PointerClass, "[]", drb_ffi__ZTSPFiP11sqlite3_vfsPKciPiE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_35PointerClass, "[]=", drb_ffi__ZTSPFiP11sqlite3_vfsPKciPiE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_35PointerClass, "nil?", drb_ffi__ZTSPFiP11sqlite3_vfsPKciPiE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_36PointerClass = drb_api->mrb_define_class_under(state, module, "Function_36Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_36PointerClass, "new", drb_ffi__ZTSPFiP11sqlite3_vfsPKciPcE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_36PointerClass, "value", drb_ffi__ZTSPFiP11sqlite3_vfsPKciPcE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_36PointerClass, "[]", drb_ffi__ZTSPFiP11sqlite3_vfsPKciPcE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_36PointerClass, "[]=", drb_ffi__ZTSPFiP11sqlite3_vfsPKciPcE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_36PointerClass, "nil?", drb_ffi__ZTSPFiP11sqlite3_vfsPKciPcE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_37PointerClass = drb_api->mrb_define_class_under(state, module, "Function_37Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_37PointerClass, "new", drb_ffi__ZTSPFPvP11sqlite3_vfsPKcE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_37PointerClass, "value", drb_ffi__ZTSPFPvP11sqlite3_vfsPKcE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_37PointerClass, "[]", drb_ffi__ZTSPFPvP11sqlite3_vfsPKcE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_37PointerClass, "[]=", drb_ffi__ZTSPFPvP11sqlite3_vfsPKcE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_37PointerClass, "nil?", drb_ffi__ZTSPFPvP11sqlite3_vfsPKcE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_38PointerClass = drb_api->mrb_define_class_under(state, module, "Function_38Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_38PointerClass, "new", drb_ffi__ZTSPFvP11sqlite3_vfsiPcE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_38PointerClass, "value", drb_ffi__ZTSPFvP11sqlite3_vfsiPcE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_38PointerClass, "[]", drb_ffi__ZTSPFvP11sqlite3_vfsiPcE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_38PointerClass, "[]=", drb_ffi__ZTSPFvP11sqlite3_vfsiPcE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_38PointerClass, "nil?", drb_ffi__ZTSPFvP11sqlite3_vfsiPcE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_39PointerClass = drb_api->mrb_define_class_under(state, module, "Function_39Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_39PointerClass, "new", drb_ffi__ZTSPFPFvvEP11sqlite3_vfsPvPKcE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_39PointerClass, "value", drb_ffi__ZTSPFPFvvEP11sqlite3_vfsPvPKcE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_39PointerClass, "[]", drb_ffi__ZTSPFPFvvEP11sqlite3_vfsPvPKcE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_39PointerClass, "[]=", drb_ffi__ZTSPFPFvvEP11sqlite3_vfsPvPKcE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_39PointerClass, "nil?", drb_ffi__ZTSPFPFvvEP11sqlite3_vfsPvPKcE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_40PointerClass = drb_api->mrb_define_class_under(state, module, "Function_40Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_40PointerClass, "new", drb_ffi__ZTSPFvP11sqlite3_vfsPvE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_40PointerClass, "value", drb_ffi__ZTSPFvP11sqlite3_vfsPvE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_40PointerClass, "[]", drb_ffi__ZTSPFvP11sqlite3_vfsPvE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_40PointerClass, "[]=", drb_ffi__ZTSPFvP11sqlite3_vfsPvE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_40PointerClass, "nil?", drb_ffi__ZTSPFvP11sqlite3_vfsPvE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_41PointerClass = drb_api->mrb_define_class_under(state, module, "Function_41Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_41PointerClass, "new", drb_ffi__ZTSPFiP11sqlite3_vfsiPcE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_41PointerClass, "value", drb_ffi__ZTSPFiP11sqlite3_vfsiPcE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_41PointerClass, "[]", drb_ffi__ZTSPFiP11sqlite3_vfsiPcE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_41PointerClass, "[]=", drb_ffi__ZTSPFiP11sqlite3_vfsiPcE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_41PointerClass, "nil?", drb_ffi__ZTSPFiP11sqlite3_vfsiPcE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_42PointerClass = drb_api->mrb_define_class_under(state, module, "Function_42Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_42PointerClass, "new", drb_ffi__ZTSPFiP11sqlite3_vfsiE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_42PointerClass, "value", drb_ffi__ZTSPFiP11sqlite3_vfsiE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_42PointerClass, "[]", drb_ffi__ZTSPFiP11sqlite3_vfsiE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_42PointerClass, "[]=", drb_ffi__ZTSPFiP11sqlite3_vfsiE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_42PointerClass, "nil?", drb_ffi__ZTSPFiP11sqlite3_vfsiE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_43PointerClass = drb_api->mrb_define_class_under(state, module, "Function_43Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_43PointerClass, "new", drb_ffi__ZTSPFiP11sqlite3_vfsPdE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_43PointerClass, "value", drb_ffi__ZTSPFiP11sqlite3_vfsPdE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_43PointerClass, "[]", drb_ffi__ZTSPFiP11sqlite3_vfsPdE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_43PointerClass, "[]=", drb_ffi__ZTSPFiP11sqlite3_vfsPdE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_43PointerClass, "nil?", drb_ffi__ZTSPFiP11sqlite3_vfsPdE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_44PointerClass = drb_api->mrb_define_class_under(state, module, "Function_44Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_44PointerClass, "new", drb_ffi__ZTSPFiP11sqlite3_vfsPxE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_44PointerClass, "value", drb_ffi__ZTSPFiP11sqlite3_vfsPxE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_44PointerClass, "[]", drb_ffi__ZTSPFiP11sqlite3_vfsPxE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_44PointerClass, "[]=", drb_ffi__ZTSPFiP11sqlite3_vfsPxE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_44PointerClass, "nil?", drb_ffi__ZTSPFiP11sqlite3_vfsPxE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_45PointerClass = drb_api->mrb_define_class_under(state, module, "Function_45Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_45PointerClass, "new", drb_ffi__ZTSPFiP11sqlite3_vfsPKcPFvvEE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_45PointerClass, "value", drb_ffi__ZTSPFiP11sqlite3_vfsPKcPFvvEE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_45PointerClass, "[]", drb_ffi__ZTSPFiP11sqlite3_vfsPKcPFvvEE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_45PointerClass, "[]=", drb_ffi__ZTSPFiP11sqlite3_vfsPKcPFvvEE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_45PointerClass, "nil?", drb_ffi__ZTSPFiP11sqlite3_vfsPKcPFvvEE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_46PointerClass = drb_api->mrb_define_class_under(state, module, "Function_46Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_46PointerClass, "new", drb_ffi__ZTSPFPFvvEP11sqlite3_vfsPKcE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_46PointerClass, "value", drb_ffi__ZTSPFPFvvEP11sqlite3_vfsPKcE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_46PointerClass, "[]", drb_ffi__ZTSPFPFvvEP11sqlite3_vfsPKcE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_46PointerClass, "[]=", drb_ffi__ZTSPFPFvvEP11sqlite3_vfsPKcE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_46PointerClass, "nil?", drb_ffi__ZTSPFPFvvEP11sqlite3_vfsPKcE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_47PointerClass = drb_api->mrb_define_class_under(state, module, "Function_47Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_47PointerClass, "new", drb_ffi__ZTSPFPKcP11sqlite3_vfsS0_E_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_47PointerClass, "value", drb_ffi__ZTSPFPKcP11sqlite3_vfsS0_E_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_47PointerClass, "[]", drb_ffi__ZTSPFPKcP11sqlite3_vfsS0_E_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_47PointerClass, "[]=", drb_ffi__ZTSPFPKcP11sqlite3_vfsS0_E_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_47PointerClass, "nil?", drb_ffi__ZTSPFPKcP11sqlite3_vfsS0_E_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Sqlite3_index_constraintPointerClass = drb_api->mrb_define_class_under(state, module, "Sqlite3_index_constraintPointer", object_class);
    drb_api->mrb_define_class_method(state, Sqlite3_index_constraintPointerClass, "new", drb_ffi__ZTSP24sqlite3_index_constraint_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_index_constraintPointerClass, "value", drb_ffi__ZTSP24sqlite3_index_constraint_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_index_constraintPointerClass, "[]", drb_ffi__ZTSP24sqlite3_index_constraint_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_index_constraintPointerClass, "[]=", drb_ffi__ZTSP24sqlite3_index_constraint_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Sqlite3_index_constraintPointerClass, "nil?", drb_ffi__ZTSP24sqlite3_index_constraint_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Sqlite3_index_orderbyPointerClass = drb_api->mrb_define_class_under(state, module, "Sqlite3_index_orderbyPointer", object_class);
    drb_api->mrb_define_class_method(state, Sqlite3_index_orderbyPointerClass, "new", drb_ffi__ZTSP21sqlite3_index_orderby_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_index_orderbyPointerClass, "value", drb_ffi__ZTSP21sqlite3_index_orderby_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_index_orderbyPointerClass, "[]", drb_ffi__ZTSP21sqlite3_index_orderby_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_index_orderbyPointerClass, "[]=", drb_ffi__ZTSP21sqlite3_index_orderby_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Sqlite3_index_orderbyPointerClass, "nil?", drb_ffi__ZTSP21sqlite3_index_orderby_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Sqlite3_index_constraint_usagePointerClass = drb_api->mrb_define_class_under(state, module, "Sqlite3_index_constraint_usagePointer", object_class);
    drb_api->mrb_define_class_method(state, Sqlite3_index_constraint_usagePointerClass, "new", drb_ffi__ZTSP30sqlite3_index_constraint_usage_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_index_constraint_usagePointerClass, "value", drb_ffi__ZTSP30sqlite3_index_constraint_usage_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_index_constraint_usagePointerClass, "[]", drb_ffi__ZTSP30sqlite3_index_constraint_usage_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_index_constraint_usagePointerClass, "[]=", drb_ffi__ZTSP30sqlite3_index_constraint_usage_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Sqlite3_index_constraint_usagePointerClass, "nil?", drb_ffi__ZTSP30sqlite3_index_constraint_usage_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_48PointerClass = drb_api->mrb_define_class_under(state, module, "Function_48Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_48PointerClass, "new", drb_ffi__ZTSPFiP12sqlite3_fileE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_48PointerClass, "value", drb_ffi__ZTSPFiP12sqlite3_fileE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_48PointerClass, "[]", drb_ffi__ZTSPFiP12sqlite3_fileE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_48PointerClass, "[]=", drb_ffi__ZTSPFiP12sqlite3_fileE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_48PointerClass, "nil?", drb_ffi__ZTSPFiP12sqlite3_fileE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_49PointerClass = drb_api->mrb_define_class_under(state, module, "Function_49Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_49PointerClass, "new", drb_ffi__ZTSPFiP12sqlite3_filePvixE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_49PointerClass, "value", drb_ffi__ZTSPFiP12sqlite3_filePvixE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_49PointerClass, "[]", drb_ffi__ZTSPFiP12sqlite3_filePvixE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_49PointerClass, "[]=", drb_ffi__ZTSPFiP12sqlite3_filePvixE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_49PointerClass, "nil?", drb_ffi__ZTSPFiP12sqlite3_filePvixE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_50PointerClass = drb_api->mrb_define_class_under(state, module, "Function_50Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_50PointerClass, "new", drb_ffi__ZTSPFiP12sqlite3_filePKvixE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_50PointerClass, "value", drb_ffi__ZTSPFiP12sqlite3_filePKvixE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_50PointerClass, "[]", drb_ffi__ZTSPFiP12sqlite3_filePKvixE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_50PointerClass, "[]=", drb_ffi__ZTSPFiP12sqlite3_filePKvixE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_50PointerClass, "nil?", drb_ffi__ZTSPFiP12sqlite3_filePKvixE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_51PointerClass = drb_api->mrb_define_class_under(state, module, "Function_51Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_51PointerClass, "new", drb_ffi__ZTSPFiP12sqlite3_filexE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_51PointerClass, "value", drb_ffi__ZTSPFiP12sqlite3_filexE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_51PointerClass, "[]", drb_ffi__ZTSPFiP12sqlite3_filexE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_51PointerClass, "[]=", drb_ffi__ZTSPFiP12sqlite3_filexE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_51PointerClass, "nil?", drb_ffi__ZTSPFiP12sqlite3_filexE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_52PointerClass = drb_api->mrb_define_class_under(state, module, "Function_52Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_52PointerClass, "new", drb_ffi__ZTSPFiP12sqlite3_fileiE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_52PointerClass, "value", drb_ffi__ZTSPFiP12sqlite3_fileiE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_52PointerClass, "[]", drb_ffi__ZTSPFiP12sqlite3_fileiE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_52PointerClass, "[]=", drb_ffi__ZTSPFiP12sqlite3_fileiE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_52PointerClass, "nil?", drb_ffi__ZTSPFiP12sqlite3_fileiE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_53PointerClass = drb_api->mrb_define_class_under(state, module, "Function_53Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_53PointerClass, "new", drb_ffi__ZTSPFiP12sqlite3_filePxE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_53PointerClass, "value", drb_ffi__ZTSPFiP12sqlite3_filePxE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_53PointerClass, "[]", drb_ffi__ZTSPFiP12sqlite3_filePxE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_53PointerClass, "[]=", drb_ffi__ZTSPFiP12sqlite3_filePxE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_53PointerClass, "nil?", drb_ffi__ZTSPFiP12sqlite3_filePxE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_54PointerClass = drb_api->mrb_define_class_under(state, module, "Function_54Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_54PointerClass, "new", drb_ffi__ZTSPFiP12sqlite3_filePiE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_54PointerClass, "value", drb_ffi__ZTSPFiP12sqlite3_filePiE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_54PointerClass, "[]", drb_ffi__ZTSPFiP12sqlite3_filePiE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_54PointerClass, "[]=", drb_ffi__ZTSPFiP12sqlite3_filePiE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_54PointerClass, "nil?", drb_ffi__ZTSPFiP12sqlite3_filePiE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_55PointerClass = drb_api->mrb_define_class_under(state, module, "Function_55Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_55PointerClass, "new", drb_ffi__ZTSPFiP12sqlite3_fileiPvE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_55PointerClass, "value", drb_ffi__ZTSPFiP12sqlite3_fileiPvE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_55PointerClass, "[]", drb_ffi__ZTSPFiP12sqlite3_fileiPvE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_55PointerClass, "[]=", drb_ffi__ZTSPFiP12sqlite3_fileiPvE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_55PointerClass, "nil?", drb_ffi__ZTSPFiP12sqlite3_fileiPvE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_56PointerClass = drb_api->mrb_define_class_under(state, module, "Function_56Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_56PointerClass, "new", drb_ffi__ZTSPFiP12sqlite3_fileiiiPPVvE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_56PointerClass, "value", drb_ffi__ZTSPFiP12sqlite3_fileiiiPPVvE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_56PointerClass, "[]", drb_ffi__ZTSPFiP12sqlite3_fileiiiPPVvE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_56PointerClass, "[]=", drb_ffi__ZTSPFiP12sqlite3_fileiiiPPVvE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_56PointerClass, "nil?", drb_ffi__ZTSPFiP12sqlite3_fileiiiPPVvE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_57PointerClass = drb_api->mrb_define_class_under(state, module, "Function_57Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_57PointerClass, "new", drb_ffi__ZTSPFiP12sqlite3_fileiiiE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_57PointerClass, "value", drb_ffi__ZTSPFiP12sqlite3_fileiiiE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_57PointerClass, "[]", drb_ffi__ZTSPFiP12sqlite3_fileiiiE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_57PointerClass, "[]=", drb_ffi__ZTSPFiP12sqlite3_fileiiiE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_57PointerClass, "nil?", drb_ffi__ZTSPFiP12sqlite3_fileiiiE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_58PointerClass = drb_api->mrb_define_class_under(state, module, "Function_58Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_58PointerClass, "new", drb_ffi__ZTSPFvP12sqlite3_fileE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_58PointerClass, "value", drb_ffi__ZTSPFvP12sqlite3_fileE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_58PointerClass, "[]", drb_ffi__ZTSPFvP12sqlite3_fileE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_58PointerClass, "[]=", drb_ffi__ZTSPFvP12sqlite3_fileE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_58PointerClass, "nil?", drb_ffi__ZTSPFvP12sqlite3_fileE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_59PointerClass = drb_api->mrb_define_class_under(state, module, "Function_59Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_59PointerClass, "new", drb_ffi__ZTSPFiP12sqlite3_filexiPPvE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_59PointerClass, "value", drb_ffi__ZTSPFiP12sqlite3_filexiPPvE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_59PointerClass, "[]", drb_ffi__ZTSPFiP12sqlite3_filexiPPvE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_59PointerClass, "[]=", drb_ffi__ZTSPFiP12sqlite3_filexiPPvE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_59PointerClass, "nil?", drb_ffi__ZTSPFiP12sqlite3_filexiPPvE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Function_60PointerClass = drb_api->mrb_define_class_under(state, module, "Function_60Pointer", object_class);
    drb_api->mrb_define_class_method(state, Function_60PointerClass, "new", drb_ffi__ZTSPFiP12sqlite3_filexPvE_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_60PointerClass, "value", drb_ffi__ZTSPFiP12sqlite3_filexPvE_GetValue, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Function_60PointerClass, "[]", drb_ffi__ZTSPFiP12sqlite3_filexPvE_GetAt, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Function_60PointerClass, "[]=", drb_ffi__ZTSPFiP12sqlite3_filexPvE_SetAt, MRB_ARGS_REQ(2));
    drb_api->mrb_define_method(state, Function_60PointerClass, "nil?", drb_ffi__ZTSPFiP12sqlite3_filexPvE_IsNil, MRB_ARGS_REQ(0));
    struct RClass *Sqlite3_fileClass = drb_api->mrb_define_class_under(state, module, "Sqlite3_file", object_class);
    drb_api->mrb_define_class_method(state, Sqlite3_fileClass, "new", drb_ffi__ZTS12sqlite3_file_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_fileClass, "pMethods", drb_ffi__ZTS12sqlite3_file_pMethods_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_fileClass, "pMethods=", drb_ffi__ZTS12sqlite3_file_pMethods_Set, MRB_ARGS_REQ(1));
    struct RClass *Sqlite3_moduleClass = drb_api->mrb_define_class_under(state, module, "Sqlite3_module", object_class);
    drb_api->mrb_define_class_method(state, Sqlite3_moduleClass, "new", drb_ffi__ZTS14sqlite3_module_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_moduleClass, "iVersion", drb_ffi__ZTS14sqlite3_module_iVersion_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_moduleClass, "iVersion=", drb_ffi__ZTS14sqlite3_module_iVersion_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_moduleClass, "xCreate", drb_ffi__ZTS14sqlite3_module_xCreate_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_moduleClass, "xCreate=", drb_ffi__ZTS14sqlite3_module_xCreate_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_moduleClass, "xConnect", drb_ffi__ZTS14sqlite3_module_xConnect_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_moduleClass, "xConnect=", drb_ffi__ZTS14sqlite3_module_xConnect_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_moduleClass, "xBestIndex", drb_ffi__ZTS14sqlite3_module_xBestIndex_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_moduleClass, "xBestIndex=", drb_ffi__ZTS14sqlite3_module_xBestIndex_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_moduleClass, "xDisconnect", drb_ffi__ZTS14sqlite3_module_xDisconnect_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_moduleClass, "xDisconnect=", drb_ffi__ZTS14sqlite3_module_xDisconnect_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_moduleClass, "xDestroy", drb_ffi__ZTS14sqlite3_module_xDestroy_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_moduleClass, "xDestroy=", drb_ffi__ZTS14sqlite3_module_xDestroy_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_moduleClass, "xOpen", drb_ffi__ZTS14sqlite3_module_xOpen_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_moduleClass, "xOpen=", drb_ffi__ZTS14sqlite3_module_xOpen_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_moduleClass, "xClose", drb_ffi__ZTS14sqlite3_module_xClose_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_moduleClass, "xClose=", drb_ffi__ZTS14sqlite3_module_xClose_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_moduleClass, "xFilter", drb_ffi__ZTS14sqlite3_module_xFilter_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_moduleClass, "xFilter=", drb_ffi__ZTS14sqlite3_module_xFilter_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_moduleClass, "xNext", drb_ffi__ZTS14sqlite3_module_xNext_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_moduleClass, "xNext=", drb_ffi__ZTS14sqlite3_module_xNext_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_moduleClass, "xEof", drb_ffi__ZTS14sqlite3_module_xEof_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_moduleClass, "xEof=", drb_ffi__ZTS14sqlite3_module_xEof_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_moduleClass, "xColumn", drb_ffi__ZTS14sqlite3_module_xColumn_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_moduleClass, "xColumn=", drb_ffi__ZTS14sqlite3_module_xColumn_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_moduleClass, "xRowid", drb_ffi__ZTS14sqlite3_module_xRowid_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_moduleClass, "xRowid=", drb_ffi__ZTS14sqlite3_module_xRowid_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_moduleClass, "xUpdate", drb_ffi__ZTS14sqlite3_module_xUpdate_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_moduleClass, "xUpdate=", drb_ffi__ZTS14sqlite3_module_xUpdate_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_moduleClass, "xBegin", drb_ffi__ZTS14sqlite3_module_xBegin_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_moduleClass, "xBegin=", drb_ffi__ZTS14sqlite3_module_xBegin_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_moduleClass, "xSync", drb_ffi__ZTS14sqlite3_module_xSync_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_moduleClass, "xSync=", drb_ffi__ZTS14sqlite3_module_xSync_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_moduleClass, "xCommit", drb_ffi__ZTS14sqlite3_module_xCommit_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_moduleClass, "xCommit=", drb_ffi__ZTS14sqlite3_module_xCommit_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_moduleClass, "xRollback", drb_ffi__ZTS14sqlite3_module_xRollback_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_moduleClass, "xRollback=", drb_ffi__ZTS14sqlite3_module_xRollback_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_moduleClass, "xFindFunction", drb_ffi__ZTS14sqlite3_module_xFindFunction_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_moduleClass, "xFindFunction=", drb_ffi__ZTS14sqlite3_module_xFindFunction_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_moduleClass, "xRename", drb_ffi__ZTS14sqlite3_module_xRename_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_moduleClass, "xRename=", drb_ffi__ZTS14sqlite3_module_xRename_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_moduleClass, "xSavepoint", drb_ffi__ZTS14sqlite3_module_xSavepoint_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_moduleClass, "xSavepoint=", drb_ffi__ZTS14sqlite3_module_xSavepoint_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_moduleClass, "xRelease", drb_ffi__ZTS14sqlite3_module_xRelease_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_moduleClass, "xRelease=", drb_ffi__ZTS14sqlite3_module_xRelease_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_moduleClass, "xRollbackTo", drb_ffi__ZTS14sqlite3_module_xRollbackTo_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_moduleClass, "xRollbackTo=", drb_ffi__ZTS14sqlite3_module_xRollbackTo_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_moduleClass, "xShadowName", drb_ffi__ZTS14sqlite3_module_xShadowName_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_moduleClass, "xShadowName=", drb_ffi__ZTS14sqlite3_module_xShadowName_Set, MRB_ARGS_REQ(1));
    struct RClass *Sqlite3_vfsClass = drb_api->mrb_define_class_under(state, module, "Sqlite3_vfs", object_class);
    drb_api->mrb_define_class_method(state, Sqlite3_vfsClass, "new", drb_ffi__ZTS11sqlite3_vfs_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_vfsClass, "iVersion", drb_ffi__ZTS11sqlite3_vfs_iVersion_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_vfsClass, "iVersion=", drb_ffi__ZTS11sqlite3_vfs_iVersion_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_vfsClass, "szOsFile", drb_ffi__ZTS11sqlite3_vfs_szOsFile_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_vfsClass, "szOsFile=", drb_ffi__ZTS11sqlite3_vfs_szOsFile_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_vfsClass, "mxPathname", drb_ffi__ZTS11sqlite3_vfs_mxPathname_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_vfsClass, "mxPathname=", drb_ffi__ZTS11sqlite3_vfs_mxPathname_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_vfsClass, "pNext", drb_ffi__ZTS11sqlite3_vfs_pNext_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_vfsClass, "pNext=", drb_ffi__ZTS11sqlite3_vfs_pNext_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_vfsClass, "zName", drb_ffi__ZTS11sqlite3_vfs_zName_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_vfsClass, "zName=", drb_ffi__ZTS11sqlite3_vfs_zName_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_vfsClass, "pAppData", drb_ffi__ZTS11sqlite3_vfs_pAppData_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_vfsClass, "pAppData=", drb_ffi__ZTS11sqlite3_vfs_pAppData_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_vfsClass, "xOpen", drb_ffi__ZTS11sqlite3_vfs_xOpen_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_vfsClass, "xOpen=", drb_ffi__ZTS11sqlite3_vfs_xOpen_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_vfsClass, "xDelete", drb_ffi__ZTS11sqlite3_vfs_xDelete_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_vfsClass, "xDelete=", drb_ffi__ZTS11sqlite3_vfs_xDelete_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_vfsClass, "xAccess", drb_ffi__ZTS11sqlite3_vfs_xAccess_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_vfsClass, "xAccess=", drb_ffi__ZTS11sqlite3_vfs_xAccess_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_vfsClass, "xFullPathname", drb_ffi__ZTS11sqlite3_vfs_xFullPathname_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_vfsClass, "xFullPathname=", drb_ffi__ZTS11sqlite3_vfs_xFullPathname_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_vfsClass, "xDlOpen", drb_ffi__ZTS11sqlite3_vfs_xDlOpen_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_vfsClass, "xDlOpen=", drb_ffi__ZTS11sqlite3_vfs_xDlOpen_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_vfsClass, "xDlError", drb_ffi__ZTS11sqlite3_vfs_xDlError_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_vfsClass, "xDlError=", drb_ffi__ZTS11sqlite3_vfs_xDlError_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_vfsClass, "xDlSym", drb_ffi__ZTS11sqlite3_vfs_xDlSym_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_vfsClass, "xDlSym=", drb_ffi__ZTS11sqlite3_vfs_xDlSym_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_vfsClass, "xDlClose", drb_ffi__ZTS11sqlite3_vfs_xDlClose_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_vfsClass, "xDlClose=", drb_ffi__ZTS11sqlite3_vfs_xDlClose_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_vfsClass, "xRandomness", drb_ffi__ZTS11sqlite3_vfs_xRandomness_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_vfsClass, "xRandomness=", drb_ffi__ZTS11sqlite3_vfs_xRandomness_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_vfsClass, "xSleep", drb_ffi__ZTS11sqlite3_vfs_xSleep_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_vfsClass, "xSleep=", drb_ffi__ZTS11sqlite3_vfs_xSleep_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_vfsClass, "xCurrentTime", drb_ffi__ZTS11sqlite3_vfs_xCurrentTime_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_vfsClass, "xCurrentTime=", drb_ffi__ZTS11sqlite3_vfs_xCurrentTime_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_vfsClass, "xGetLastError", drb_ffi__ZTS11sqlite3_vfs_xGetLastError_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_vfsClass, "xGetLastError=", drb_ffi__ZTS11sqlite3_vfs_xGetLastError_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_vfsClass, "xCurrentTimeInt64", drb_ffi__ZTS11sqlite3_vfs_xCurrentTimeInt64_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_vfsClass, "xCurrentTimeInt64=", drb_ffi__ZTS11sqlite3_vfs_xCurrentTimeInt64_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_vfsClass, "xSetSystemCall", drb_ffi__ZTS11sqlite3_vfs_xSetSystemCall_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_vfsClass, "xSetSystemCall=", drb_ffi__ZTS11sqlite3_vfs_xSetSystemCall_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_vfsClass, "xGetSystemCall", drb_ffi__ZTS11sqlite3_vfs_xGetSystemCall_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_vfsClass, "xGetSystemCall=", drb_ffi__ZTS11sqlite3_vfs_xGetSystemCall_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_vfsClass, "xNextSystemCall", drb_ffi__ZTS11sqlite3_vfs_xNextSystemCall_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_vfsClass, "xNextSystemCall=", drb_ffi__ZTS11sqlite3_vfs_xNextSystemCall_Set, MRB_ARGS_REQ(1));
    struct RClass *Sqlite3_index_infoClass = drb_api->mrb_define_class_under(state, module, "Sqlite3_index_info", object_class);
    drb_api->mrb_define_class_method(state, Sqlite3_index_infoClass, "new", drb_ffi__ZTS18sqlite3_index_info_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_index_infoClass, "nConstraint", drb_ffi__ZTS18sqlite3_index_info_nConstraint_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_index_infoClass, "nConstraint=", drb_ffi__ZTS18sqlite3_index_info_nConstraint_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_index_infoClass, "aConstraint", drb_ffi__ZTS18sqlite3_index_info_aConstraint_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_index_infoClass, "aConstraint=", drb_ffi__ZTS18sqlite3_index_info_aConstraint_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_index_infoClass, "nOrderBy", drb_ffi__ZTS18sqlite3_index_info_nOrderBy_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_index_infoClass, "nOrderBy=", drb_ffi__ZTS18sqlite3_index_info_nOrderBy_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_index_infoClass, "aOrderBy", drb_ffi__ZTS18sqlite3_index_info_aOrderBy_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_index_infoClass, "aOrderBy=", drb_ffi__ZTS18sqlite3_index_info_aOrderBy_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_index_infoClass, "aConstraintUsage", drb_ffi__ZTS18sqlite3_index_info_aConstraintUsage_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_index_infoClass, "aConstraintUsage=", drb_ffi__ZTS18sqlite3_index_info_aConstraintUsage_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_index_infoClass, "idxNum", drb_ffi__ZTS18sqlite3_index_info_idxNum_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_index_infoClass, "idxNum=", drb_ffi__ZTS18sqlite3_index_info_idxNum_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_index_infoClass, "idxStr", drb_ffi__ZTS18sqlite3_index_info_idxStr_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_index_infoClass, "idxStr=", drb_ffi__ZTS18sqlite3_index_info_idxStr_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_index_infoClass, "needToFreeIdxStr", drb_ffi__ZTS18sqlite3_index_info_needToFreeIdxStr_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_index_infoClass, "needToFreeIdxStr=", drb_ffi__ZTS18sqlite3_index_info_needToFreeIdxStr_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_index_infoClass, "orderByConsumed", drb_ffi__ZTS18sqlite3_index_info_orderByConsumed_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_index_infoClass, "orderByConsumed=", drb_ffi__ZTS18sqlite3_index_info_orderByConsumed_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_index_infoClass, "estimatedCost", drb_ffi__ZTS18sqlite3_index_info_estimatedCost_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_index_infoClass, "estimatedCost=", drb_ffi__ZTS18sqlite3_index_info_estimatedCost_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_index_infoClass, "estimatedRows", drb_ffi__ZTS18sqlite3_index_info_estimatedRows_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_index_infoClass, "estimatedRows=", drb_ffi__ZTS18sqlite3_index_info_estimatedRows_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_index_infoClass, "idxFlags", drb_ffi__ZTS18sqlite3_index_info_idxFlags_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_index_infoClass, "idxFlags=", drb_ffi__ZTS18sqlite3_index_info_idxFlags_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_index_infoClass, "colUsed", drb_ffi__ZTS18sqlite3_index_info_colUsed_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_index_infoClass, "colUsed=", drb_ffi__ZTS18sqlite3_index_info_colUsed_Set, MRB_ARGS_REQ(1));
    struct RClass *Sqlite3_io_methodsClass = drb_api->mrb_define_class_under(state, module, "Sqlite3_io_methods", object_class);
    drb_api->mrb_define_class_method(state, Sqlite3_io_methodsClass, "new", drb_ffi__ZTS18sqlite3_io_methods_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_io_methodsClass, "iVersion", drb_ffi__ZTS18sqlite3_io_methods_iVersion_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_io_methodsClass, "iVersion=", drb_ffi__ZTS18sqlite3_io_methods_iVersion_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_io_methodsClass, "xClose", drb_ffi__ZTS18sqlite3_io_methods_xClose_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_io_methodsClass, "xClose=", drb_ffi__ZTS18sqlite3_io_methods_xClose_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_io_methodsClass, "xRead", drb_ffi__ZTS18sqlite3_io_methods_xRead_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_io_methodsClass, "xRead=", drb_ffi__ZTS18sqlite3_io_methods_xRead_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_io_methodsClass, "xWrite", drb_ffi__ZTS18sqlite3_io_methods_xWrite_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_io_methodsClass, "xWrite=", drb_ffi__ZTS18sqlite3_io_methods_xWrite_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_io_methodsClass, "xTruncate", drb_ffi__ZTS18sqlite3_io_methods_xTruncate_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_io_methodsClass, "xTruncate=", drb_ffi__ZTS18sqlite3_io_methods_xTruncate_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_io_methodsClass, "xSync", drb_ffi__ZTS18sqlite3_io_methods_xSync_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_io_methodsClass, "xSync=", drb_ffi__ZTS18sqlite3_io_methods_xSync_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_io_methodsClass, "xFileSize", drb_ffi__ZTS18sqlite3_io_methods_xFileSize_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_io_methodsClass, "xFileSize=", drb_ffi__ZTS18sqlite3_io_methods_xFileSize_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_io_methodsClass, "xLock", drb_ffi__ZTS18sqlite3_io_methods_xLock_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_io_methodsClass, "xLock=", drb_ffi__ZTS18sqlite3_io_methods_xLock_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_io_methodsClass, "xUnlock", drb_ffi__ZTS18sqlite3_io_methods_xUnlock_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_io_methodsClass, "xUnlock=", drb_ffi__ZTS18sqlite3_io_methods_xUnlock_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_io_methodsClass, "xCheckReservedLock", drb_ffi__ZTS18sqlite3_io_methods_xCheckReservedLock_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_io_methodsClass, "xCheckReservedLock=", drb_ffi__ZTS18sqlite3_io_methods_xCheckReservedLock_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_io_methodsClass, "xFileControl", drb_ffi__ZTS18sqlite3_io_methods_xFileControl_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_io_methodsClass, "xFileControl=", drb_ffi__ZTS18sqlite3_io_methods_xFileControl_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_io_methodsClass, "xSectorSize", drb_ffi__ZTS18sqlite3_io_methods_xSectorSize_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_io_methodsClass, "xSectorSize=", drb_ffi__ZTS18sqlite3_io_methods_xSectorSize_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_io_methodsClass, "xDeviceCharacteristics", drb_ffi__ZTS18sqlite3_io_methods_xDeviceCharacteristics_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_io_methodsClass, "xDeviceCharacteristics=", drb_ffi__ZTS18sqlite3_io_methods_xDeviceCharacteristics_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_io_methodsClass, "xShmMap", drb_ffi__ZTS18sqlite3_io_methods_xShmMap_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_io_methodsClass, "xShmMap=", drb_ffi__ZTS18sqlite3_io_methods_xShmMap_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_io_methodsClass, "xShmLock", drb_ffi__ZTS18sqlite3_io_methods_xShmLock_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_io_methodsClass, "xShmLock=", drb_ffi__ZTS18sqlite3_io_methods_xShmLock_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_io_methodsClass, "xShmBarrier", drb_ffi__ZTS18sqlite3_io_methods_xShmBarrier_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_io_methodsClass, "xShmBarrier=", drb_ffi__ZTS18sqlite3_io_methods_xShmBarrier_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_io_methodsClass, "xShmUnmap", drb_ffi__ZTS18sqlite3_io_methods_xShmUnmap_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_io_methodsClass, "xShmUnmap=", drb_ffi__ZTS18sqlite3_io_methods_xShmUnmap_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_io_methodsClass, "xFetch", drb_ffi__ZTS18sqlite3_io_methods_xFetch_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_io_methodsClass, "xFetch=", drb_ffi__ZTS18sqlite3_io_methods_xFetch_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_io_methodsClass, "xUnfetch", drb_ffi__ZTS18sqlite3_io_methods_xUnfetch_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_io_methodsClass, "xUnfetch=", drb_ffi__ZTS18sqlite3_io_methods_xUnfetch_Set, MRB_ARGS_REQ(1));
    struct RClass *Sqlite3_index_constraintClass = drb_api->mrb_define_class_under(state, module, "Sqlite3_index_constraint", object_class);
    drb_api->mrb_define_class_method(state, Sqlite3_index_constraintClass, "new", drb_ffi__ZTS24sqlite3_index_constraint_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_index_constraintClass, "iColumn", drb_ffi__ZTS24sqlite3_index_constraint_iColumn_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_index_constraintClass, "iColumn=", drb_ffi__ZTS24sqlite3_index_constraint_iColumn_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_index_constraintClass, "op", drb_ffi__ZTS24sqlite3_index_constraint_op_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_index_constraintClass, "op=", drb_ffi__ZTS24sqlite3_index_constraint_op_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_index_constraintClass, "usable", drb_ffi__ZTS24sqlite3_index_constraint_usable_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_index_constraintClass, "usable=", drb_ffi__ZTS24sqlite3_index_constraint_usable_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_index_constraintClass, "iTermOffset", drb_ffi__ZTS24sqlite3_index_constraint_iTermOffset_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_index_constraintClass, "iTermOffset=", drb_ffi__ZTS24sqlite3_index_constraint_iTermOffset_Set, MRB_ARGS_REQ(1));
    struct RClass *Sqlite3_index_orderbyClass = drb_api->mrb_define_class_under(state, module, "Sqlite3_index_orderby", object_class);
    drb_api->mrb_define_class_method(state, Sqlite3_index_orderbyClass, "new", drb_ffi__ZTS21sqlite3_index_orderby_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_index_orderbyClass, "iColumn", drb_ffi__ZTS21sqlite3_index_orderby_iColumn_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_index_orderbyClass, "iColumn=", drb_ffi__ZTS21sqlite3_index_orderby_iColumn_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_index_orderbyClass, "desc", drb_ffi__ZTS21sqlite3_index_orderby_desc_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_index_orderbyClass, "desc=", drb_ffi__ZTS21sqlite3_index_orderby_desc_Set, MRB_ARGS_REQ(1));
    struct RClass *Sqlite3_index_constraint_usageClass = drb_api->mrb_define_class_under(state, module, "Sqlite3_index_constraint_usage", object_class);
    drb_api->mrb_define_class_method(state, Sqlite3_index_constraint_usageClass, "new", drb_ffi__ZTS30sqlite3_index_constraint_usage_New, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_index_constraint_usageClass, "argvIndex", drb_ffi__ZTS30sqlite3_index_constraint_usage_argvIndex_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_index_constraint_usageClass, "argvIndex=", drb_ffi__ZTS30sqlite3_index_constraint_usage_argvIndex_Set, MRB_ARGS_REQ(1));
    drb_api->mrb_define_method(state, Sqlite3_index_constraint_usageClass, "omit", drb_ffi__ZTS30sqlite3_index_constraint_usage_omit_Get, MRB_ARGS_REQ(0));
    drb_api->mrb_define_method(state, Sqlite3_index_constraint_usageClass, "omit=", drb_ffi__ZTS30sqlite3_index_constraint_usage_omit_Set, MRB_ARGS_REQ(1));
}
