/*
 *                         OpenSplice DDS
 *
 *   This software and documentation are Copyright 2006 to TO_YEAR PrismTech
 *   Limited, its affiliated companies and licensors. All rights reserved.
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 */
#ifndef _AST_VALUE_FWD_HH
#define _AST_VALUE_FWD_HH


// Representation of a forward interface declaration

/*
** DEPENDENCIES: ast_decl.hh, ast_interface.hh, utl_scoped_name.hh,
**   utl_strlist.hh
**
** USE: Included from ast.hh
*/

class AST_ValueFwd : public virtual AST_Type
{

public:
   // Operations

   // Constructor(s)
   AST_ValueFwd();
   AST_ValueFwd
   (
      bool abstract,
      UTL_ScopedName *n, 
      const UTL_Pragmas &p
   );
   virtual ~AST_ValueFwd()
   {}

   // Data Accessors
   AST_Value *full_definition();
   void set_full_definition(AST_Value *val);

   // Narrowing
   DEF_NARROW_METHODS1(AST_ValueFwd, AST_Type);
   DEF_NARROW_FROM_DECL(AST_ValueFwd);

   // AST Dumping
   virtual void dump(ostream &);

private:
   // Data
   AST_Value *pd_full_definition; // The value this is a forward declaration of
};

#endif           // _AST_VALUE_FWD_HH
