/******************************************************************************/
/* hex_def.h                                                                  */
/******************************************************************************/


#ifndef __HEX_DEF_H
#define __HEX_DEF_H



/********************************** Constants *********************************/
#define DATA_BUFF_LEN           (2048)
#define MAXLEN_HEX_STRING       (523)               // Maxlen row string hex-file
#define ENCRYPT_BOUNDARY        (DATA_BUFF_LEN/2)


/*************************** Prototypes struct for HEX ************************/
typedef enum
{
    eHEX_DATA = 0,                      // Data
    eHEX_FILE_END,                      // File end
    eHEX_SEG_ADDR,                      // Segment addr
    eHEX_SEG_ST_ADDR,                   // Segment start addr
    eHEX_LINE_ADDR,                     // Line addr
    eHEX_LINE_ST_ADDR,                  // Line start addr
    eHEX_UNDEF_REC                      // Undef rec
} __TYPEREC_HEX;                        // Rec type


typedef struct
{
    uint8_t Reclen;                     // Len data\info
    uint16_t Offset;                    // Addr offset
    __TYPEREC_HEX TypeRec;              // Type rec
    uint8_t RowData[256];               // Data
} __RECLEN_HEADER_HEX;                  // Header hex-string


typedef struct
{
    uint8_t Data[DATA_BUFF_LEN];        // ����� ��� ������
    uint32_t DataLen;                   // ���������� ������ � ������
} __BUFF_TOOLS_HEX;                     // ��� �������� ����� ������


typedef struct
{
    bool_t FlgFileEnd;                  // ���� - ���� ��������
} __FLG_HEX;                            // ��� ����� hex-�����


typedef struct
{
    uint32_t DataCount;                 // ������� ������
    uint32_t FwCrc;                     // ����������� ����� fw
    uint32_t CurrAddr;                  // ����� �������� hex-�����
} __PARSING_TOOLS_HEX;                  // ��� ����������� ��� ��������


typedef struct
{
    __aes_context ctx_enc;
    uint8_t iv[16];
} __ENCRYPT_TOOLS_HEX;                  // ����������� ��� ����������


#endif