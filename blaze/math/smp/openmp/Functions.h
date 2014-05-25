//=================================================================================================
/*!
//  \file blaze/math/smp/openmp/Functions.h
//  \brief Header file for the OpenMP-based SMP utility functions
//
//  Copyright (C) 2013 Klaus Iglberger - All Rights Reserved
//
//  This file is part of the Blaze library. You can redistribute it and/or modify it under
//  the terms of the New (Revised) BSD License. Redistribution and use in source and binary
//  forms, with or without modification, are permitted provided that the following conditions
//  are met:
//
//  1. Redistributions of source code must retain the above copyright notice, this list of
//     conditions and the following disclaimer.
//  2. Redistributions in binary form must reproduce the above copyright notice, this list
//     of conditions and the following disclaimer in the documentation and/or other materials
//     provided with the distribution.
//  3. Neither the names of the Blaze development group nor the names of its contributors
//     may be used to endorse or promote products derived from this software without specific
//     prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
//  EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
//  OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
//  SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
//  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
//  TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
//  BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
//  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
//  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
//  DAMAGE.
*/
//=================================================================================================

#ifndef _BLAZE_MATH_SMP_OPENMP_FUNCTIONS_H_
#define _BLAZE_MATH_SMP_OPENMP_FUNCTIONS_H_


//*************************************************************************************************
// Includes
//*************************************************************************************************

#include <stdexcept>
#include <omp.h>


namespace blaze {

//=================================================================================================
//
//  SMP UTILITY FUNCTIONS
//
//=================================================================================================

//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Returns the number of threads used for OpenMP parallel operations.
// \ingroup smp
//
// \return The number of threads used for OpenMP parallel operations.
//
// Via this function the number of threads used for OpenMP parallel operations can be queried.
// The function generally reflects the number of threads as set by the OMP_NUM_THREADS environment
// variable, the \c omp_set_num_threads() library function, or the blaze::setNumThreads() function.
*/
inline size_t getNumThreads()
{
   return omp_get_max_threads();
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Sets the number of threads to be used for OpenMP parallel operations.
// \ingroup smp
//
// \param number The given number of threads \f$[1..\infty)\f$.
// \return void
// \exception std::invalid_argument Invalid number of threads.
//
// Via this function the maximum number of threads for OpenMP parallel operations can be specified.
// Note that the given \a number must be in the range \f$[1..\infty)\f$. In case an invalid number
// of threads is specified, a \a std::invalid_argument exception is thrown.
*/
inline size_t setNumThreads( size_t number )
{
   if( number == 0UL )
      throw std::invalid_argument( "Invalid number of threads" );

   omp_set_num_threads( number );
}
/*! \endcond */
//*************************************************************************************************

} // namespace blaze

#endif