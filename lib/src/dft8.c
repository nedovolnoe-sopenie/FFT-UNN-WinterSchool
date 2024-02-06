#include "dft.h"

extern void dft8Fwd(const cfloat32_t *pSrc, cfloat32_t *pDst)
{
    float      twdPi4    = 0x1.6a09e6p-1;
    cfloat32_t tmpSrc[4];
    cfloat32_t tmpDst[8];
    cfloat32_t tmp5;
    cfloat32_t tmp7;
    // dft4 - 0, 2, 4, 6
    tmpSrc[0].re = pSrc[0].re   + pSrc[4].re;
    tmpSrc[0].im = pSrc[0].im   + pSrc[4].im;
    tmpSrc[1].re = pSrc[0].re   - pSrc[4].re;
    tmpSrc[1].im = pSrc[0].im   - pSrc[4].im;
    tmpSrc[2].re = pSrc[2].re   + pSrc[6].re;
    tmpSrc[2].im = pSrc[2].im   + pSrc[6].im;
    tmpSrc[3].re = pSrc[2].re   - pSrc[6].re;
    tmpSrc[3].im = pSrc[2].im   - pSrc[6].im;
    tmpDst[0].re = tmpSrc[0].re + tmpSrc[2].re;
    tmpDst[0].im = tmpSrc[0].im + tmpSrc[2].im;
    tmpDst[1].re = tmpSrc[1].re + tmpSrc[3].im;
    tmpDst[1].im = tmpSrc[1].im - tmpSrc[3].re;
    tmpDst[2].re = tmpSrc[0].re - tmpSrc[2].re;
    tmpDst[2].im = tmpSrc[0].im - tmpSrc[2].im;
    tmpDst[3].re = tmpSrc[1].re - tmpSrc[3].im;
    tmpDst[3].im = tmpSrc[1].im + tmpSrc[3].re;
    // dft4 - 1, 3, 5, 7
    tmpSrc[0].re = pSrc[1].re   + pSrc[5].re;
    tmpSrc[0].im = pSrc[1].im   + pSrc[5].im;
    tmpSrc[1].re = pSrc[1].re   - pSrc[5].re;
    tmpSrc[1].im = pSrc[1].im   - pSrc[5].im;
    tmpSrc[2].re = pSrc[3].re   + pSrc[7].re;
    tmpSrc[2].im = pSrc[3].im   + pSrc[7].im;
    tmpSrc[3].re = pSrc[3].re   - pSrc[7].re;
    tmpSrc[3].im = pSrc[3].im   - pSrc[7].im;
    tmpDst[4].re = tmpSrc[0].re + tmpSrc[2].re;
    tmpDst[4].im = tmpSrc[0].im + tmpSrc[2].im;
    tmpDst[5].re = tmpSrc[1].re + tmpSrc[3].im;
    tmpDst[5].im = tmpSrc[1].im - tmpSrc[3].re;
    tmpDst[6].im =-tmpSrc[0].re + tmpSrc[2].re; // factoring in twiddles
    tmpDst[6].re = tmpSrc[0].im - tmpSrc[2].im; // factoring in twiddles
    tmpDst[7].re = tmpSrc[1].re - tmpSrc[3].im;
    tmpDst[7].im = tmpSrc[1].im + tmpSrc[3].re;
    // twiddle factors
    tmp5.re      = twdPi4 * ( tmpDst[5].re + tmpDst[5].im);
    tmp5.im      = twdPi4 * (-tmpDst[5].re + tmpDst[5].im);
    tmpDst[5].re = tmp5.re;
    tmpDst[5].im = tmp5.im;
    tmp7.re      = twdPi4 * (-tmpDst[7].re + tmpDst[7].im);
    tmp7.im      = twdPi4 * (-tmpDst[7].re - tmpDst[7].im);
    tmpDst[7].re = tmp7.re;
    tmpDst[7].im = tmp7.im;
    // dft2 - 0, 4
    pDst[4].re   = tmpDst[0].re - tmpDst[4].re;
    pDst[4].im   = tmpDst[0].im - tmpDst[4].im;
    pDst[0].re   = tmpDst[0].re + tmpDst[4].re;
    pDst[0].im   = tmpDst[0].im + tmpDst[4].im;
    // dft2 - 1, 5
    pDst[5].re   = tmpDst[1].re - tmpDst[5].re;
    pDst[5].im   = tmpDst[1].im - tmpDst[5].im;
    pDst[1].re   = tmpDst[1].re + tmpDst[5].re;
    pDst[1].im   = tmpDst[1].im + tmpDst[5].im;
    // dft2 - 2, 6
    pDst[6].re   = tmpDst[2].re - tmpDst[6].re;
    pDst[6].im   = tmpDst[2].im - tmpDst[6].im;
    pDst[2].re   = tmpDst[2].re + tmpDst[6].re;
    pDst[2].im   = tmpDst[2].im + tmpDst[6].im;
    // dft2 - 3, 7
    pDst[7].re   = tmpDst[3].re - tmpDst[7].re;
    pDst[7].im   = tmpDst[3].im - tmpDst[7].im;
    pDst[3].re   = tmpDst[3].re + tmpDst[7].re;
    pDst[3].im   = tmpDst[3].im + tmpDst[7].im;
