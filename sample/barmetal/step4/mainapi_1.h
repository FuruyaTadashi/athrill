/*******************************************************************************************/
/*  File Name      : mainapi_1.h                                                           */
/*  Contents       : The main header file of FlexRay node1.                                */
/*  Author         : NEC Electronics Corporation                                           */
/*  History        :                                                                       */
/*           Date         Version   Auther                       Note                      */
/*           2008.01.31   V01.00    NEC Electronics Corporation  New creation              */
/*                                                                                         */
/*******************************************************************************************/
/*******************************************************************************************/
/* �v���g�^�C�v�錾                                                                        */
/*******************************************************************************************/
static void Set_MsgNoBuff(void);

/*******************************************************************************************/
/* define�錾                                                                              */
/*******************************************************************************************/
/* ���m�[�h�ԍ� */
#define NODE_NO                         NODE_NO1

/* ���b�Z�[�W���M�o�b�t�@�ԍ��ꗗ */
/* (clusterNode_1.h��BufferHeader_u16[128][10]�̃��b�Z�[�W�o�b�t�@�ԍ�) */
#define SF_SEND_MSGID_SENDCNT           ((u08)0x0)    /* ���M�񐔃t���[��(node1)        */
#define SF_SEND_MSGID_LED               ((u08)0x3)    /* LED�f�[�^�t���[��(node1)       */
#define DF_SEND_MSGID_NMI_A             ((u08)0x6)    /* NMI�����񐔃t���[�� chA(node1) */
#define DF_SEND_MSGID_NMI_B             ((u08)0x7)    /* NMI�����񐔃t���[�� chB(node1) */

/* ���b�Z�[�W��M�o�b�t�@�ԍ��ꗗ */
/* (clusterNode_1.h��BufferHeader_u16[128][10]�̃��b�Z�[�W�o�b�t�@�ԍ�) */
#define SF_REC1_MSGID_SENDCNT           ((u08)0x1)    /* ���M�񐔃t���[��(node2)        */
#define SF_REC2_MSGID_SENDCNT           ((u08)0x2)    /* ���M�񐔃t���[��(node3)        */
#define SF_REC1_MSGID_LED               ((u08)0x4)    /* LED�f�[�^�t���[��(node2)       */
#define SF_REC2_MSGID_LED               ((u08)0x5)    /* LED�f�[�^�t���[��(node3)       */
#define DF_REC1_MSGID_NMI_A             ((u08)0x8)    /* NMI�����񐔃t���[�� chA(node2) */
#define DF_REC1_MSGID_NMI_B             ((u08)0x9)    /* NMI�����񐔃t���[�� chB(node2) */
#define DF_REC2_MSGID_NMI_A             ((u08)0xa)    /* NMI�����񐔃t���[�� chA(node3) */
#define DF_REC2_MSGID_NMI_B             ((u08)0xb)    /* NMI�����񐔃t���[�� chB(node3) */
