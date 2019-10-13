/*  说明
    为了把Landsat 8 采集到的黑白影像转换成彩色影像，需要把3张TIFF格式的灰度图合成为1张JPEG格式的彩色图。因为，如果产生1张jpeg格式的彩色图，就不需要专业的软件来浏览。为了避免数据量大造成的软件崩溃，可以将1张jpeg格式的彩色图分割为多张jpeg格式的彩色图。本文在Ubuntu 18.04操作系统上，借助gdal已有的文章写成。 */

#include "gdal.h"
#include "cpl_conv.h"

int main()
{
	GDALDatasetH  hDatasetRed, hDatasetGreen, hDatasetBlue;
	GDALAllRegister();
	unsigned short *pafScanlineRed, *pafScanlineGreen, *pafScanlineBlue;

	int OPEN();
	int TIFF2JPEG();
	int WRITE();
	return TRUE;
}

int OPEN()
{
	hDatasetRed   = GDALOpen( TIFFRedFileName  , GA_ReadOnly );
	hDatasetGreen = GDALOpen( TIFFGreenFileName, GA_ReadOnly );
	hDatasetBlue  = GDALOpen( TIFFBlueFileName , GA_ReadOnly );
    	if( hDatasetRed == NULL || hDatasetGreen == NULL || hDatasetBlue == NULL )
    	{
		printf("Error in OPEN().");
    	}

	GDALRasterBandH hBandRed, hBandGreen, hBandBlue;
	int             nBlockXSize, nBlockYSize;
	int             bGotMin, bGotMax;
	double          adfMinMax[2];
	hBandRed   = GDALGetRasterBand( hDatasetRed  , 1 );
	hBandGreen = GDALGetRasterBand( hDatasetGreen, 1 );
	hBandBlue  = GDALGetRasterBand( hDatasetBlue , 1 );
	GDALGetBlockSize( hBandRed, &nBlockXSize, &nBlockYSize );
	printf( "Block=%dx%d Type=%s, ColorInterp=%s\n",
	        nBlockXSize, nBlockYSize,
	        GDALGetDataTypeName(GDALGetRasterDataType(hBandRed)),
	        GDALGetColorInterpretationName(
	            GDALGetRasterColorInterpretation(hBandRed)) );
	adfMinMax[0] = GDALGetRasterMinimum( hBandRed, &bGotMin );
	adfMinMax[1] = GDALGetRasterMaximum( hBandRed, &bGotMax );
	if( ! (bGotMin && bGotMax) )
	    GDALComputeRasterMinMax( hBandRed, TRUE, adfMinMax );
	printf( "Min=%.3fd, Max=%.3f\n", adfMinMax[0], adfMinMax[1] );
	if( GDALGetOverviewCount(hBandRed) > 0 )
	    printf( "Band has %d overviews.\n", GDALGetOverviewCount(hBandRed));
	if( GDALGetRasterColorTable( hBandRed ) != NULL )
	    printf( "Band has a color table with %d entries.\n",
	             GDALGetColorEntryCount(
	                 GDALGetRasterColorTable( hBandRed ) ) );

	int   nXSize = GDALGetRasterBandXSize( hBandRed );
	int   nYSize = GDALGetRasterBandYSize( hBandRed );
	pafScanlineRed   = (unsigned short *) CPLMalloc(sizeof(unsigned short)*nXSize*nYSize);
	pafScanlineGreen = (unsigned short *) CPLMalloc(sizeof(unsigned short)*nXSize*nYSize);
	pafScanlineBlue  = (unsigned short *) CPLMalloc(sizeof(unsigned short)*nXSize*nYSize);
	GDALRasterIO( hBandRed, GF_Read, 0, 0, nXSize, nYSize,
	              pafScanlineRed, nXSize, nYSize, GDT_UInt16,
	              0, 0 );
	GDALRasterIO( hBandGreen, GF_Read, 0, 0, nXSize, nYSize,
	              pafScanlineGreen, nXSize, nYSize, GDT_UInt16,
	              0, 0 );
	GDALRasterIO( hBandBlue, GF_Read, 0, 0, nXSize, nYSize,
	              pafScanlineBlue, nXSize, nYSize, GDT_UInt16,
	              0, 0 );
}

int TIFF2JPEG(){}

int WRITE(){}
