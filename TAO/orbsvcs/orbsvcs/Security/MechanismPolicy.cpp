// -*- C++ -*-

#include "MechanismPolicy.h"

ACE_RCSID (Security,
           MechanismPolicy,
           "$Id$")

TAO_MechanismPolicy::TAO_MechanismPolicy (
  const Security::MechanismTypeList &mechanisms)
  : mechanisms_ (mechanisms)
{
}

TAO_MechanismPolicy::~TAO_MechanismPolicy (void)
{
}

CORBA::PolicyType
TAO_MechanismPolicy::policy_type (CORBA::Environment & /* ACE_TRY_ENV */)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  return Security::SecMechanismPolicy;
}

CORBA::Policy_ptr
TAO_MechanismPolicy::copy (CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  TAO_MechanismPolicy *policy = 0;
  ACE_NEW_THROW_EX (policy,
                    TAO_MechanismPolicy (this->mechanisms_),
                    CORBA::NO_MEMORY (
                      CORBA::SystemException::_tao_minor_code (
                        TAO_DEFAULT_MINOR_CODE,
                        ENOMEM),
                      CORBA::COMPLETED_NO));
  ACE_CHECK_RETURN (CORBA::Policy::_nil ());

  return policy;
}

void
TAO_MechanismPolicy::destroy (CORBA::Environment & /* ACE_TRY_ENV */)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
}

Security::MechanismTypeList *
TAO_MechanismPolicy::mechanisms (CORBA::Environment &ACE_TRY_ENV)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  Security::MechanismTypeList *mechs = 0;
  ACE_NEW_THROW_EX (mechs,
                    Security::MechanismTypeList (this->mechanisms_),
                    CORBA::NO_MEMORY (
                      CORBA::SystemException::_tao_minor_code (
                        TAO_DEFAULT_MINOR_CODE,
                        ENOMEM),
                      CORBA::COMPLETED_NO));
  ACE_CHECK_RETURN (0);

  return mechs;
}
