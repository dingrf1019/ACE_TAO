// -*- C++ -*-

//=============================================================================
/**
 *  @file    TypeCodeFactory_Adapter.h
 *
 *  $Id$
 *
 *  @author  Jeff Parsons <parsons@cs.wustl.edu>
 */
//=============================================================================

#ifndef TAO_TYPECODEFACTORY_ADAPTER_H
#define TAO_TYPECODEFACTORY_ADAPTER_H

#include /**/ "ace/pre.h"
#include "ace/Service_Object.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/SystemException.h"
#include "tao/Environment.h"
#include "tao/ValueModifierC.h"
#include "tao/Typecode_typesC.h"

namespace CORBA
{
  class EnumMemberSeq;
  class StructMemberSeq;
  class UnionMemberSeq;
  class ValueMemberSeq;
}

namespace TAO
{
  namespace TypeCode
  {
    template<typename STRING_TYPE> class Case;
    template<typename STRING_TYPE> class Enumerator;
    template<typename STRING_TYPE> class Struct_Field;
    template<typename STRING_TYPE> class Value_Field;
  }
}


/**
 * @class TAO_TypeCodeFactory_Adapter
 *
 * @brief TAO_TypeCodeFactory_Adapter.
 *
 * Class that adapts the CORBA::ORB create_*_tc functions
 * to use the TypeCodeFactory. This is a base class for
 * the actual implementation in the TypeCodeFactory_DLL library.
 */
class TAO_Export TAO_TypeCodeFactory_Adapter : public ACE_Service_Object
{
public:
  virtual ~TAO_TypeCodeFactory_Adapter (void);

  virtual CORBA::TypeCode_ptr create_struct_tc (
      const char *id,
      const char *name,
      const CORBA::StructMemberSeq &members
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((CORBA::SystemException)) = 0;

  virtual CORBA::TypeCode_ptr create_union_tc (
      const char *id,
      const char *name,
      CORBA::TypeCode_ptr discriminator_type,
      const CORBA::UnionMemberSeq &members
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((CORBA::SystemException)) = 0;

  virtual CORBA::TypeCode_ptr create_enum_tc (
      const char *id,
      const char *name,
      const CORBA::EnumMemberSeq &members
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((CORBA::SystemException)) = 0;

  virtual CORBA::TypeCode_ptr create_alias_tc (
      const char *id,
      const char *name,
      CORBA::TypeCode_ptr original_type
      ACE_ENV_ARG_DECL
    )

    ACE_THROW_SPEC ((CORBA::SystemException)) = 0;
  virtual CORBA::TypeCode_ptr create_exception_tc (
      const char *id,
      const char *name,
      const CORBA::StructMemberSeq &members
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((CORBA::SystemException)) = 0;

  virtual CORBA::TypeCode_ptr create_interface_tc (
      const char *id,
      const char *name
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((CORBA::SystemException)) = 0;

  virtual CORBA::TypeCode_ptr create_string_tc (
      CORBA::ULong bound
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((CORBA::SystemException)) = 0;

  virtual CORBA::TypeCode_ptr create_wstring_tc (
      CORBA::ULong bound
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((CORBA::SystemException)) = 0;

  virtual CORBA::TypeCode_ptr create_fixed_tc (
      CORBA::UShort digits,
      CORBA::UShort scale
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((CORBA::SystemException)) = 0;

  virtual CORBA::TypeCode_ptr create_sequence_tc (
      CORBA::ULong bound,
      CORBA::TypeCode_ptr element_type
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((CORBA::SystemException)) = 0;

  virtual CORBA::TypeCode_ptr create_array_tc (
      CORBA::ULong length,
      CORBA::TypeCode_ptr element_type
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((CORBA::SystemException)) = 0;

  virtual CORBA::TypeCode_ptr create_value_tc (
      const char *id,
      const char *name,
      CORBA::ValueModifier type_modifier,
      CORBA::TypeCode_ptr concrete_base,
      const CORBA::ValueMemberSeq &members
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((CORBA::SystemException)) = 0;

  virtual CORBA::TypeCode_ptr create_value_box_tc (
      const char *id,
      const char *name,
      CORBA::TypeCode_ptr boxed_type
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((CORBA::SystemException)) = 0;

  virtual CORBA::TypeCode_ptr create_native_tc (
      const char *id,
      const char *name
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((CORBA::SystemException)) = 0;

  virtual CORBA::TypeCode_ptr create_recursive_tc (
      const char *id
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((CORBA::SystemException)) = 0;

  virtual CORBA::TypeCode_ptr create_abstract_interface_tc (
      const char *id,
      const char *name
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((CORBA::SystemException)) = 0;

  virtual CORBA::TypeCode_ptr create_local_interface_tc (
      const char *id,
      const char *name
      ACE_ENV_ARG_DECL
    )
    ACE_THROW_SPEC ((CORBA::SystemException)) = 0;

  virtual CORBA::TypeCode_ptr create_component_tc (
      const char *id,
      const char *name
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((CORBA::SystemException)) = 0;

  virtual CORBA::TypeCode_ptr create_home_tc (
      const char *id,
      const char *name
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((CORBA::SystemException)) = 0;

  virtual CORBA::TypeCode_ptr create_event_tc (
      const char *id,
      const char *name,
      CORBA::ValueModifier type_modifier,
      CORBA::TypeCode_ptr concrete_base,
      const CORBA::ValueMemberSeq &members
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((CORBA::SystemException)) = 0;

  // --

  // Factory methods that has no corresponding TypeCodeFactory IDL,
  // i.e. it is TAO-specific.

  virtual bool _tao_make_typecode (TAO_InputCDR & cdr,
                                   CORBA::TypeCode *& tc) = 0;

  virtual CORBA::TypeCode_ptr _tao_create_enum_tc (
    CORBA::TCKind,
    char const * id,
    char const * name,
    TAO::TypeCode::Enumerator<char const *> const *,
    CORBA::ULong ncases
    ACE_ENV_ARG_DECL) = 0;

  virtual CORBA::TypeCode_ptr _tao_create_struct_except_tc (
    CORBA::TCKind,
    char const * id,
    char const * name,
    TAO::TypeCode::Struct_Field<char const *> const * fields,
    CORBA::ULong nfields
    ACE_ENV_ARG_DECL) = 0;

    virtual CORBA::TypeCode_ptr _tao_create_union_tc (
      char const * id,
      char const * name,
      CORBA::TypeCode_ptr * discriminant_type,
      TAO::TypeCode::Case<char const *> const *,
      CORBA::ULong ncases,
      CORBA::Long default_index,
      char const * default_case_name,
      CORBA::TypeCode_ptr * default_case_type
      ACE_ENV_ARG_DECL) = 0;

  virtual CORBA::TypeCode_ptr _tao_create_value_event_tc (
    CORBA::TCKind,
    char const * id,
    char const * name,
    CORBA::ValueModifier modifier,
    CORBA::TypeCode_ptr const * concrete_base,
    TAO::TypeCode::Value_Field<char const *> const * fields,
    CORBA::ULong nfields
    ACE_ENV_ARG_DECL) = 0;

};

#include /**/ "ace/post.h"

#endif /* TAO_TYPECODEFACTORY_ADAPTER_H */
