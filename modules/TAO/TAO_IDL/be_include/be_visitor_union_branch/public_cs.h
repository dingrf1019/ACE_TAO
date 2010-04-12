/* -*- c++ -*- */

//=============================================================================
/**
 *  @file    public_cs.h
 *
 *  $Id$
 *
 *   Visitor for the Union class.
 *   This one generates code for public part of the union class for the union
 *   members in the client stubs.
 *
 *
 *  @author Aniruddha Gokhale
 */
//=============================================================================


#ifndef _BE_VISITOR_UNION_BRANCS_PUBLIC_CS_H_
#define _BE_VISITOR_UNION_BRANCS_PUBLIC_CS_H_

/**
 * @class be_visitor_union_branch_public_cs
 *
 * @brief be_visitor_union_branch_public_cs
 *
 * This visitor is used to generate implementation such as typecodes for
 * constructed types
 */
class be_visitor_union_branch_public_cs : public be_visitor_decl
{
public:
  /// constructor
  be_visitor_union_branch_public_cs (be_visitor_context *ctx);

  /// destructor
  ~be_visitor_union_branch_public_cs (void);

  /// visit the union_branch node
  virtual int visit_union_branch (be_union_branch *node);

  // =visit operations on all possible data types that a union_branch can be

  /// visit array type
  virtual int visit_array (be_array *node);

  /// visit enum type
  virtual int visit_enum (be_enum *node);

  /// visit sequence type
  virtual int visit_sequence (be_sequence *node);

  /// visit string type
  virtual int visit_string (be_string *node);

  /// visit structure type
  virtual int visit_structure (be_structure *node);

  /// visit union type
  virtual int visit_union (be_union *node);
};

#endif /* _BE_VISITOR_UNION_BRANCS_PUBLIC_CS_H_ */
