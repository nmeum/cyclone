/**
 ** This file was automatically generated by the Cyclone scheme compiler
 **
 ** (c) 2014 Justin Ethier
 ** Version 0.0.1 (Pre-release)
 **
 **/

#define funcall1(cfn,a1) if (type_of(cfn) == cons_tag || prim(cfn)) { Cyc_apply(0, (closure)a1, cfn); } else { ((cfn)->fn)(1,cfn,a1);}
/* Return to continuation after checking for stack overflow. */
#define return_funcall1(cfn,a1) \
{char stack; \
 if (check_overflow(&stack,stack_limit1)) { \
     object buf[1]; buf[0] = a1;\
     GC(cfn,buf,1); return; \
 } else {funcall1((closure) (cfn),a1); return;}}

/* Evaluate an expression after checking for stack overflow. */
#define return_check1(_fn,a1) { \
 char stack; \
 if (check_overflow(&stack,stack_limit1)) { \
     object buf[1]; buf[0] = a1; \
     mclosure0(c1, _fn); \
     GC(&c1, buf, 1); return; \
 } else { (_fn)(1,(closure)_fn,a1); }}

#define funcall2(cfn,a1,a2) if (type_of(cfn) == cons_tag || prim(cfn)) { Cyc_apply(1, (closure)a1, cfn,a2); } else { ((cfn)->fn)(2,cfn,a1,a2);}
/* Return to continuation after checking for stack overflow. */
#define return_funcall2(cfn,a1,a2) \
{char stack; \
 if (check_overflow(&stack,stack_limit1)) { \
     object buf[2]; buf[0] = a1;buf[1] = a2;\
     GC(cfn,buf,2); return; \
 } else {funcall2((closure) (cfn),a1,a2); return;}}

/* Evaluate an expression after checking for stack overflow. */
#define return_check2(_fn,a1,a2) { \
 char stack; \
 if (check_overflow(&stack,stack_limit1)) { \
     object buf[2]; buf[0] = a1;buf[1] = a2; \
     mclosure0(c1, _fn); \
     GC(&c1, buf, 2); return; \
 } else { (_fn)(2,(closure)_fn,a1,a2); }}

#include "cyclone.h"
object __glo_lib1_91hello = nil;
object __glo_internal_91func = nil;
object __glo_lib1_91test = nil;
extern object __glo__85Cyc_91version_91banner_85;
extern object __glo_call_91with_91current_91continuation;
extern object __glo_call_95cc;
extern object __glo_char_123_127;
extern object __glo_char_121_127;
extern object __glo_char_125_127;
extern object __glo_char_121_123_127;
extern object __glo_char_125_123_127;
extern object __glo_char_91upcase;
extern object __glo_char_91downcase;
extern object __glo_char_91alphabetic_127;
extern object __glo_char_91upper_91case_127;
extern object __glo_char_91lower_91case_127;
extern object __glo_char_91numeric_127;
extern object __glo_char_91whitespace_127;
extern object __glo_digit_91value;
extern object __glo_foldl;
extern object __glo_foldr;
extern object __glo_not;
extern object __glo_list_127;
extern object __glo_zero_127;
extern object __glo_positive_127;
extern object __glo_negative_127;
extern object __glo_append;
extern object __glo__list;
extern object __glo_make_91list;
extern object __glo_list_91copy;
extern object __glo_map;
extern object __glo_for_91each;
extern object __glo_list_91tail;
extern object __glo_list_91ref;
extern object __glo_list_91set_67;
extern object __glo_reverse;
extern object __glo_boolean_123_127;
extern object __glo_symbol_123_127;
extern object __glo_Cyc_91obj_123_127;
extern object __glo_make_91string;
extern object __glo_error;
extern object __glo_raise;
extern object __glo_raise_91continuable;
extern object __glo_with_91exception_91handler;
extern object __glo__85exception_91handler_91stack_85;
extern object __glo_Cyc_91add_91exception_91handler;
extern object __glo_Cyc_91remove_91exception_91handler;
extern object __glo_lib2_91hello;
#include "runtime.h"
void __lambda_2(int argc, closure _,object k_738) ;
void __lambda_1(int argc, object self_7310, object r_739) ;
void __lambda_0(int argc, closure _,object k_735) ;

void __lambda_2(int argc, closure _,object k_738) {
  
closureN_type c_7318;
c_7318.tag = closureN_tag;
 c_7318.fn = __lambda_1;
c_7318.num_elt = 1;
c_7318.elts = (object *)alloca(sizeof(object) * 1);
c_7318.elts[0] = k_738;

return_funcall1(  __glo_internal_91func,  &c_7318);; 
}

void __lambda_1(int argc, object self_7310, object r_739) {
  
make_int(c_7321, 1);
return_funcall1(  ((closureN)self_7310)->elts[0],  &c_7321);; 
}

void __lambda_0(int argc, closure _,object k_735) {
  return_funcall1(  k_735,  Cyc_write(__glo_lib2_91hello));; 
}

void c_libslib1_entry_pt(argc, cont) int argc; closure cont; { 
  printf("Initializing lib1\n");

  add_global((object *) &__glo_lib1_91hello);
  add_global((object *) &__glo_internal_91func);
  add_global((object *) &__glo_lib1_91test);
  mclosure0(c_7316, (function_type)__lambda_2); 
  __glo_lib1_91hello = &c_7316; 
  mclosure0(c_7312, (function_type)__lambda_0); 
  __glo_internal_91func = &c_7312; 
  make_string(c_7311, "test of include from a library"); 
  __glo_lib1_91test = &c_7311; 

  make_cvar(cvar_7325, (object *)&__glo_lib1_91hello);make_cons(pair_7326, find_or_add_symbol("lib1-hello"), &cvar_7325);
  make_cvar(cvar_7327, (object *)&__glo_internal_91func);make_cons(pair_7328, find_or_add_symbol("internal-func"), &cvar_7327);
  make_cvar(cvar_7329, (object *)&__glo_lib1_91test);make_cons(pair_7330, find_or_add_symbol("lib1-test"), &cvar_7329);
make_cons(c_7333, &pair_7326,Cyc_global_variables);
make_cons(c_7332, &pair_7328, &c_7333);
make_cons(c_7331, &pair_7330, &c_7332);
Cyc_global_variables = &c_7331;

if (((closure)cont)->tag == closure1_tag) {
    ((cont)->fn)(1, ((closure1_type *)cont)->elt1);
} else {
    ((cont)->fn)(0, cont);
}}
