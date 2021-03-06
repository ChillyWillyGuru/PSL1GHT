/* sqrtf4 -
   Copyright (C) 2006, 2007 Sony Computer Entertainment Inc.
   All rights reserved.

   Redistribution and use in source and binary forms,
   with or without modification, are permitted provided that the
   following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the Sony Computer Entertainment Inc nor the names
      of its contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
   ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
   POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef ___SIMD_MATH_RSQRTF4_H___
#define ___SIMD_MATH_RSQRTF4_H___

#include <simdmath.h>
#include <altivec.h>

#include <simdmath/_vec_utils.h>

/* rsqrtf4 - for each of four float slots, compute reciprocal square root.
 * Undefined if input < 0.
 */

static inline vector float
_rsqrtf4 (vector float x)
{ 
  /* Reciprocal square root estimate and 1 Newton-Raphson iteration. */
 
  vector float zero = __vec_splatsf4(0.0f);
  vector float half = __vec_splatsf4(0.5f);
  vector float one = __vec_splatsf4(1.0f);
  vector float y0, y0x, y0half;

  y0 = vec_rsqrte( x );
  y0x = vec_madd( y0, x, zero );
  y0half = vec_madd( y0, half, zero );
  return vec_madd( vec_nmsub( y0, y0x, one ), y0half, y0 );
}

#endif
