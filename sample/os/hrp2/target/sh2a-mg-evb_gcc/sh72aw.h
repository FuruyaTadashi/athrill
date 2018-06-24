/*
 *  TOPPERS/HRP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      High Reliable system Profile Kernel
 *	
 *	Copyright (C) 2011-2012 by Embedded and Real-Time Systems Laboratory
 *				Graduate School of Information Science, Nagoya Univ., JAPAN  
 *	
 *	�嵭����Ԥϡ��ʲ���(1)��(4)�ξ������������˸¤ꡤ�ܥ��եȥ���
 *	�����ܥ��եȥ���������Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ������
 *	�ѡ������ۡʰʲ������ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
 *	(1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭������
 *		��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ���
 *		����������˴ޤޤ�Ƥ��뤳�ȡ�
 *	(2) �ܥ��եȥ������򡤥饤�֥������ʤɡ�¾�Υ��եȥ�������ȯ�˻�
 *		�ѤǤ�����Ǻ����ۤ�����ˤϡ������ۤ�ȼ���ɥ�����ȡ�����
 *		�ԥޥ˥奢��ʤɡˤˡ��嵭�����ɽ�����������Ѿ�浪��Ӳ���
 *		��̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *	(3) �ܥ��եȥ������򡤵�����Ȥ߹���ʤɡ�¾�Υ��եȥ�������ȯ�˻�
 *		�ѤǤ��ʤ����Ǻ����ۤ�����ˤϡ����Τ����줫�ξ�����������
 *		�ȡ�
 *	  (a) �����ۤ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭����
 *		  �ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *	  (b) �����ۤη��֤��̤�������ˡ�ˤ�äơ�TOPPERS�ץ������Ȥ�
 *		  ��𤹤뤳�ȡ�
 *	(4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
 *		������⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ����դ��뤳�ȡ�
 *		�ޤ����ܥ��եȥ������Υ桼���ޤ��ϥ���ɥ桼������Τ����ʤ���
 *		ͳ�˴�Ť����ᤫ��⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ�
 *		���դ��뤳�ȡ�
 *	
 *	�ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ�
 *	���TOPPERS�ץ������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����λ�����Ū
 *	���Ф���Ŭ������ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ���
 *	�������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤��
 *	����Ǥ�����ʤ���
 *	
 */

/*
 *	SH72AW CPU�ܡ��ɤΥϡ��ɥ������񸻤����
 */

#ifndef TOPPERS_SH72AW_H
#define TOPPERS_SH72AW_H

/*
 *  ����å���Ϣ�Υ쥸����
 *  ����å��Υ������ϡ��ᥤ�󥯥�å���20MHz�� or PLL��120MHz��160MHz��
 *  �����ʬ�����ơ�CPU�Υ���å��Ȥ����SCDR��
 *  �����ʬ�����ơ��Х�����å���BCDR�ˡ����յ�ǽ����å�A��B�Ȥ����PBCDR��
 */
#define SPR0 0xff46e063 /* �����ƥ�ץ�ƥ��ȥ쥸���� */
#define SPR0_CANCEL_PROTECT 0xf1 /* �ץ�ƥ��Ȳ�� */
#define SPR0_PROTECT 0x00 /* �ץ�ƥ���(0xF1�ʳ����) */

#define MCMCR 0xff46e838 /* �ᥤ�󥯥�å��ƻ뵡ǽ����쥸���� */
#define MCMCR_LXDF_MASK 0x04 /* �ᥤ�󥯥�å���ȯ����ߤ򸡽Ф������� */
#define MCMCR_LXIE 0x01 /* �ᥤ�󥯥�å�ȯ����߸��г���ߤ���� */

#define PLCR 0xff46e828 /* PLL����쥸���� */
#define PLCR_VCOD 0x0001 /* PLL�ν��ϡ�120MHz�ʤ��ΥӥåȤ�0�ˤ���ȡ�160MHz��*/

#define SCSR 0xff46e802 /* �����ƥ९��å�����쥸���� */
#define SCSR_SCS_PLL 0x01 /* PLL������ */
#define SCSR_SCS_XIN 0x00 /* �ᥤ�󥯥�å������� */

#define SCDR 0xff46e804 /* �����ƥ९��å�ʬ���쥸���� */
#define SCDR_SYSD_DIV0 0x00 /* ʬ���ʤ� */
#define SCDR_SYSD_DIV2 0x01 /* 2ʬ�� */
#define SCDR_SYSD_DIV4 0x02 /* 4ʬ�� */
#define SCDR_SYSD_DIV8 0x03 /* 8ʬ�� */
#define SCDR_SYSD_DIV16 0x04 /* 16ʬ�� */

#define BCDR 0xff46e805 /* �Х�����å� */
#define BCDR_BUSD_DIV2 0x10 /* 2ʬ�� */
#define BCDR_BUSD_DIV4 0x20 /* 4ʬ�� */

#define PBCDR 0xff46e808 /* ���յ�ǽ����å�ʬ���쥸���� */
#define PBCDR_PBAD_DIV2 0x10000000 /* ����å�A��2ʬ�� */
#define PBCDR_PBAD_DIV4 0x20000000 /* ����å�A��4ʬ�� */
#define PBCDR_PBBD_DIV0 0x00000000 /* ����å�B��ʬ���ʤ� */
#define PBCDR_PBBD_DIV2 0x00000100 /* ����å�B��2ʬ�� */

#define RDCCR 0xff46e80c /* RDC����å�����쥸������f(PBA)��ʬ�� */
#define RDCCR_RDCD_DIV0 0x00 /* ʬ���ʤ� */
#define RDCCR_RDCD_DIV2 0x01 /* 2ʬ�� */

#define COCR 0xff46e800 /* ����å����ϵ�ǽ����쥸������f(BUS)��ʬ�� */
#define COCR_COD_DIV0 0x00 /* ʬ���ʤ� */
#define COCR_COD_DIV2 0x10 /* 2ʬ�� */
#define COCR_COD_DIV4 0x20 /* 4ʬ�� */
#define COCR_COD_DIV8 0x30 /* 8ʬ�� */
#define COCR_COD_DIV16 0x40 /* 16ʬ�� */
#define COCR_COE 0x01 /* f(CLKOUT)����Ϥ���ʤ��ΥӥåȤ�0�ˤ���Ƚ��Ϥ��ʤ���*/

#define MSTPCR 0xff46e850 /* �⥸�塼�륹�ȥå�����쥸���� */
#define MSTPCR_FPUSTP 0x0001 /* FPU����ߡʺƤ�ư����뤿��ˤϥꥻ�åȤ����*/

#endif /* TOPPERS_SH72AW_H */
