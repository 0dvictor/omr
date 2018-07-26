/*******************************************************************************
 * Copyright (c) 2018, 2018 IBM Corp. and others
 *
 * This program and the accompanying materials are made available under
 * the terms of the Eclipse Public License 2.0 which accompanies this
 * distribution and is available at http://eclipse.org/legal/epl-2.0
 * or the Apache License, Version 2.0 which accompanies this distribution
 * and is available at https://www.apache.org/licenses/LICENSE-2.0.
 *
 * This Source Code may also be made available under the following Secondary
 * Licenses when the conditions for such availability set forth in the
 * Eclipse Public License, v. 2.0 are satisfied: GNU General Public License,
 * version 2 with the GNU Classpath Exception [1] and GNU General Public
 * License, version 2 with the OpenJDK Assembly Exception [2].
 *
 * [1] https://www.gnu.org/software/classpath/license.html
 * [2] http://openjdk.java.net/legal/assembly-exception.html
 *
 * SPDX-License-Identifier: EPL-2.0 OR Apache-2.0 OR GPL-2.0 WITH Classpath-exception-2.0 OR LicenseRef-GPL-2.0 WITH Assembly-exception
 *******************************************************************************/
#ifndef OMR_RUNTIME_STRUCTUREDEXCEPTIONHANDLING_INCL
#define OMR_RUNTIME_STRUCTUREDEXCEPTIONHANDLING_INCL

#ifdef __cplusplus
extern "C" {
#endif

UDATA lookupStructuredExceptionHandlerTable(UDATA methodEntry, U_32 sehOffset, UDATA pc)
   {
   if (sehOffset > 0)
      {
      I_32  offset = (I_32)(pc - methodEntry);
      I_32* entry  = (I_32*)(methodEntry + sehOffset);
      while(entry[0] != 0)
         {
         if (entry[0] == offset)
            {
            return (UDATA)(methodEntry + entry[1]);
            }
         entry += 2;
         }
      }
   return (UDATA)NULL;
   }

#ifdef __cplusplus
}
#endif
#endif
