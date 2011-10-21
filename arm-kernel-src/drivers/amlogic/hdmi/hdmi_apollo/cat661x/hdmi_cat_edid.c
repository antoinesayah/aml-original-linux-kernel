
#include "hdmi_cat_defstx.h"
#include "hdmi_i2c.h"
#include "hdmi_cat_edid.h"
#include "hdmi_cat_mddc.h"
#include "hdmi_cat_hdcp.h"
#include "hdmi_global.h"
    
#include "hdmi_debug.h"

			     unsigned short Count, unsigned char *pEDIDData) 
{
	
	
	
	
	
		
		
		
//      printf("DDC BUS HANG, Called AboutDDC()\n") ;
		    CAT_AbortDDC();
		
	
	
	
	
		
		
		    (RemainedCount >
		     DDC_FIFO_MAXREQ) ? DDC_FIFO_MAXREQ : RemainedCount;
		
		
#if 1
		    mddc_info[0] = B_MASTERDDC | B_MASTERHOST;	//switch PC
		mddc_info[1] = DDC_EDID_ADDRESS;	// for EDID ucdata get
		mddc_info[2] = bCurrOffset;
		
		
		
		
		
#else	/* 
		    
					 B_MASTERDDC | B_MASTERHOST);
		
		
		
		
		
		
#endif	/* 
		    bCurrOffset += ReqCount;
		
		
			
			
			
			
				
				
				
			
				
				
				
//                printf("Read EDID fail.\n") ;
				    return -1;
				
			
		
			
			
			
//            printf("Read EDID TimeOut. \n") ;
			    return -1;
			
		
		    //  /*    
		    do
			
			
			
		
		
		    //    */
		    //  ReadBlockHDMITX_CAT(REG_DDC_READFIFO, ReqCount, pEDIDData);
		    //    pEDIDData += ReqCount;
		}
	



//-----------------------------------------------------------
static void MonitorCapable861(Hdmi_info_para_t * info,
			      unsigned char edid_flag) 
{
	
		
	
		
	
		
		
		
		    //info->videopath_outindex = 1;    // Video Output Color Space Conversion : 0 - RGB out; 1 - YCbr (4:4:4) out; 2 - YCbr (4:2:2) out;   
		    info->videopath_outindex = 1;	// Video Output Color Space Conversion : 0 - RGB out; 1 - YCbr (4:4:4) out; 2 - YCbr (4:2:2) out;   
		}
	
		
		
		
			
		}



//-----------------------------------------------------------
static void ParsingVideoDATABlock(Hdmi_info_para_t * info, unsigned char *buff,
				  unsigned char BaseAddr,
				  unsigned char NBytes) 
{
	
	
	
		
		
			
		
			
			
			
			
		
			
			
			
			
		
			
			
			
			
		
			
			
			
			
		
			
			
			
			
		
			
			
			
			
		
			
			
			
			
		
			
			
			
			
		
			
			
			
			
		
			
			
			
			
		
			
			
			
			
		
			
			
			
			
		
			
			
			
			
		
			
			
			
			
		
			
			
		



//-----------------------------------------------------------
static void ParsingAudioDATABlock(Hdmi_info_para_t * info, unsigned char *Data,
				  unsigned char BaseAddr,
				  unsigned char NBytes) 
{
	
	
	
	do {
		
		
			
		
			
			
			    (Data[i] & 0x07);
			
				
			
				
			
				
			
				
			
				
			
				
			
				
			
				
			
				
			
				
			
		
			
			
			
				
			
				
			
				
			
				
			
				
			
				
			
				
			
			
		
			
			
			
				
			
				
			
				
			
				
			
				
			
				
			
				
			
			
		
			
			
			
				
			
				
			
				
			
				
			
				
			
				
			
				
			
			
		
			
			
			
				
			
				
			
				
			
				
			
				
			
				
			
				
			
			
		
			
			
			
				
			
				
			
				
			
				
			
				
			
				
			
				
			
			
		
			
			
			
				
			
				
			
				
			
				
			
				
			
				
			
				
			
			
		
			
			
			
				
			
				
			
				
			
				
			
				
			
				
			
				
			
			
		
			
			
		
	



//-----------------------------------------------------------
static void ParsingSpeakerDATABlock(Hdmi_info_para_t * info,
				    unsigned char *buff,
				    unsigned char BaseAddr) 
{
	
	
		
		
			
		
			
			
		
			
			
		
			
			
		
			
			
		
			
			
		
			
			
		
			
			
		
			
			
		
		



//-----------------------------------------------------------
static int ParsingCEADataBlockCollection(Hdmi_info_para_t * info,
					 unsigned char *buff) 
{
	
	
	Addr = 4;
	
//   D+=Addr;
	    AddrTag = Addr;
	
	do {
		
		
			
		
			
					       (Data & 0x1F));
			
		
			
					       (Data & 0x1F));
			
		
			
			
		
			
			     || (buff[Addr + 2] != 0x0c)
			     || (buff[Addr + 3] != 0x00))
				
				
				
				
			
			
		
		AddrTag = ++Addr;
	
	



//-----------------------------------------------------------
static void CompareTimingDescriptors(Hdmi_info_para_t * info,
				     unsigned char *Data) 
{
	
	
	{ 
		0x8C, 0x0A, 0xA0, 0x14, 0x51, 0xF0, 0x16, 0x00, 0x26, 0x7c, 0x43, 0x00, 0xc4, 0x8e,	//480i(16:9)
		0x8C, 0x0A, 0xA0, 0x20, 0x51, 0x20, 0x18, 0x10, 0x18, 0x7e, 0x23, 0x00, 0x13, 0x8e,	//576i (4:3)
		0x8C, 0x0A, 0xA0, 0x20, 0x51, 0x20, 0x18, 0x10, 0x18, 0x7e, 0x23, 0x00, 0xc4, 0x8e,	//576i (16:9)
		0x8C, 0x0A, 0xD0, 0x8A, 0x20, 0xE0, 0x2D, 0x10, 0x10, 0x3e, 0x96, 0x00, 0x13, 0x8e,	//480p (4:3) 
		0x8C, 0x0A, 0xD0, 0x8A, 0x20, 0xE0, 0x2D, 0x10, 0x10, 0x3e, 0x96, 0x00, 0xc4, 0x8e,	//480p (16:9)
		0x8C, 0x0A, 0xD0, 0x90, 0x20, 0x40, 0x31, 0x20, 0x0c, 0x40, 0x55, 0x00, 0x13, 0x8e,	//576p  (4:3) 
		0x8C, 0x0A, 0xD0, 0x90, 0x20, 0x40, 0x31, 0x20, 0x0c, 0x40, 0x55, 0x00, 0xc4, 0x8e,	//576p  (16:9)          
		0x01, 0x1D, 0x00, 0x72, 0x51, 0xD0, 0x1E, 0x20, 0x6e, 0x28, 0x55, 0x00, 0xc4, 0x8e,	//720p60(16:9)       
		0x01, 0x1D, 0x00, 0xBC, 0x52, 0xD0, 0x1E, 0x20, 0xb8, 0x28, 0x55, 0x40, 0xc4, 0x8e,	//720p50 (16:9)  
		0x01, 0x1D, 0x80, 0x18, 0x71, 0x1C, 0x16, 0x20, 0x58, 0x2c, 0x25, 0x00, 0xc4, 0x8e,	//1080i60 (16:9)  
		0x01, 0x1D, 0x80, 0xD0, 0x72, 0x1C, 0x16, 0x20, 0x10, 0x2c, 0x25, 0x80, 0xc4, 0x8e	//1080i50 (16:9)                   
	};
	
		
		
			
			
			     TimingDescriptors[index1 * 14 + index2])
				
			
		
			
			
				
			
			
				
				
				     && (Data[13] == TimingDescriptors[13]))
					
					
					
					    ("Detailed support 480i_60hz_4x3\n");
					
				
				else if ((Data[12] ==
					  TimingDescriptors[1 * 14 + 12])
					 && (Data[13] ==
					     TimingDescriptors[1 * 14 + 13]))
					
					
					
					    ("Detailed support 480i_60hz_16x9\n");
					
				
			
			
				
				
				      TimingDescriptors[2 * 14 + 12])
				     && (Data[13] ==
					 TimingDescriptors[2 * 14 + 13]))
					
					
					
					    ("Detailed support 576i_50hz_4x3\n");
					
				
				else if ((Data[12] ==
					  TimingDescriptors[3 * 14 + 12])
					 && (Data[13] ==
					     TimingDescriptors[3 * 14 + 13]))
					
					
					
					    ("Detailed support 576i_50hz_16x9\n");
					
				
			
			
				
				
				      TimingDescriptors[4 * 14 + 12])
				     && (Data[13] ==
					 TimingDescriptors[4 * 14 + 13]))
					
					
					
					    ("Detailed support 480p_60hz_4x3\n");
					
				
				else if ((Data[12] ==
					  TimingDescriptors[5 * 14 + 12])
					 && (Data[13] ==
					     TimingDescriptors[5 * 14 + 13]))
					
					
					
					    ("Detailed support 480p_60hz_16x9\n");
					
				
			
			
				
				
				      TimingDescriptors[6 * 14 + 12])
				     && (Data[13] ==
					 TimingDescriptors[6 * 14 + 13]))
					
					
					
					    ("Detailed support 576p_50hz_4x3\n");
					
				
				else if ((Data[12] ==
					  TimingDescriptors[7 * 14 + 12])
					 && (Data[13] ==
					     TimingDescriptors[7 * 14 + 13]))
					
					
					
					    ("Detailed support 576p_50hz_16x9\n");
					
				
			
				
				
				      TimingDescriptors[8 * 14 + 12])
				     && (Data[13] ==
					 TimingDescriptors[8 * 14 + 13]))
					
					
					
					    ("Detailed support 720p_60hz_16x9\n");
					
				
			
				
				
				      TimingDescriptors[9 * 14 + 12])
				     && (Data[13] ==
					 TimingDescriptors[9 * 14 + 13]))
					
					
					
					    ("Detailed support 720p_50hz_16x9\n");
					
				
			
				
				
				      TimingDescriptors[10 * 14 + 12])
				     && (Data[13] ==
					 TimingDescriptors[10 * 14 + 13]))
					
					
					    1;
					
					    ("Detailed support 1080i_60hz_16x9\n");
					
				
			
				
				
				      TimingDescriptors[11 * 14 + 12])
				     && (Data[13] ==
					 TimingDescriptors[11 * 14 + 13]))
					
					
					    1;
					
					    ("Detailed support 1080i_50hz_16x9\n");
					
				
			
				
				
			
			
		



//-----------------------------------------------------------
static void ParseCEADetailedTimingDescriptors(Hdmi_info_para_t * info,
					      unsigned char blk_mun,
					      unsigned char BaseAddr,
					      unsigned char *buff) 
{
	
	
		
		
		
		
			break;
		



/////////////////////////////////////////////////////////////////////
// CAT_ParseEDID()
// Check EDID check sum and EDID 1.3 extended segment.
/////////////////////////////////////////////////////////////////////
int CAT_ParseEDID(Hdmi_info_para_t * info) 
{
	
	
	
	
	
	if (err == -1)
		
	
//        dump(EDID_Buf,128);
//        printf(" the first edid block edid datas \n") ;       
	    for (i = 0, CheckSum = 0; i < 128; i++)
		
		
//        printf(" %02X", EDID_Buf[i]) ;
		    CheckSum += EDID_Buf[i];
		
//        if((((i + 1) % 0x10) == 0) && (i != 0) ) 
//           printf(" \n") ;    
		    
		
	
//         printf(" \n") ;
	    
		
		
		
//                 return -1 ;
		}
	
		
		
			
			
				
				
				
				
			
		
	
	else
		
		
		
		
	
	
	
		
		
		
		}
	
//    else if ( BlockCount > 4 )
//    {
//        BlockCount = 4 ;
//    }
	    
		  info->cea_on_fisrt_page <= BlockCount;
		  info->cea_on_fisrt_page++)
		
		
		    CAT_GetEDIDData(info->cea_on_fisrt_page, 0, 128, EDID_Buf);
		
			
			
//           printf(" the %dth edid block edid datas \n", info->cea_on_fisrt_page ) ;   
			    for (i = 0, CheckSum = 0; i < 128; i++)
				
				
//               printf(" %02X", EDID_Buf[i]) ;
				    CheckSum += EDID_Buf[i];
				
//               if((((i + 1) % 0x10) == 0) && (i != 0) ) 
//                  printf(" \n") ;
				    CheckSum &= 0xFF;
				
			
			      && (EDID_Buf[1] == 0x3))
				
				
				
				    ParsingCEADataBlockCollection(info,
								  EDID_Buf);
				
//                if( err != -1 )
//                      { 
				    ParseCEADetailedTimingDescriptors(info, 5,
								      EDID_Buf
								      [2],
								      EDID_Buf);
				
					
					    CABLE_PLUGIN_HDMI_OUT;
				
//                  }
//                  else 
				    //                     return -1;                                         
				}
			
//           else
//              {
//                      c= CABLE_PLUGIN_DVI_OUT;
//                return -1;
//              }
			}
		
		else
			
			
			
		
	


