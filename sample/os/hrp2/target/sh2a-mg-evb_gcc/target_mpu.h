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
 *	MPU�ɥ饤�С�SH72AW�ѡ�
 */

#ifndef TOPPERS_TARGET_MPU_H
#define TOPPERS_TARGET_MPU_H

#define MPCMPEN    0xfff78000 /* MPUͭ�� */
#define MPCRACR    0xfff78010 /* R������������ */
#define MPCWACR    0xfff78014 /* W������������ */
#define MPCIACR    0xfff78018 /* I(X)������������ */
#define MPCVLD     0xfff7801c /* �ΰ�����ͭ�� */
#define MPCACBCR   0xfff78020 /* �Хå��������ΰ�Υ��������� */
#define MPCECLR    0xfff78024 /* ���顼���ꥢ */
#define MPCESR     0xfff78028 /* ���顼���ơ����� */
#define MPCHITI    0xfff78034 /* ̿��ҥå� */
#define MPCHITO    0xfff78038 /* �ǡ����ҥåȡ��ΰ襵�����ҥå� */
#define MPCHITO_R_MASK 0x00000008 /* R���ĥե饰 */
#define MPCHITO_W_MASK 0x00000004 /* W���ĥե饰 */
#define MPCHITO_I_MASK 0x00000002 /* I���ĥե饰 */
#define MPCRSADR   0xfff7803c /* �ΰ襵�������ɥ쥹 */
#define MPCRSOP    0xfff78040 /* �ΰ襵�������� */
#define MPCRSOP_S_BIT    0x01 /* �ΰ襵�������ϥӥå� */   
#define MPCERADRI  0xfff7802c /* ̿�ᥢ���������顼���ɥ쥹 */
#define MPCERADRO  0xfff78030 /* �ǡ��������������顼���ɥ쥹 */

#define MPCSADR0   0xfff78100 /* �ΰ�0 ���ϥ��ɥ쥹 */
#define MPCSADR1   0xfff78110 /* �ΰ�1 ���ϥ��ɥ쥹 */
#define MPCSADR2   0xfff78120 /* �ΰ�2 ���ϥ��ɥ쥹 */
#define MPCSADR3   0xfff78130 /* �ΰ�3 ���ϥ��ɥ쥹 */
#define MPCSADR4   0xfff78140 /* �ΰ�4 ���ϥ��ɥ쥹 */
#define MPCSADR5   0xfff78150 /* �ΰ�5 ���ϥ��ɥ쥹 */
#define MPCSADR6   0xfff78160 /* �ΰ�6 ���ϥ��ɥ쥹 */
#define MPCSADR7   0xfff78170 /* �ΰ�7 ���ϥ��ɥ쥹 */
#define MPCSADR8   0xfff78180 /* �ΰ�8 ���ϥ��ɥ쥹 */
#define MPCSADR9   0xfff78190 /* �ΰ�9 ���ϥ��ɥ쥹 */
#define MPCSADR10  0xfff781a0 /* �ΰ�10���ϥ��ɥ쥹 */
#define MPCSADR11  0xfff781b0 /* �ΰ�11���ϥ��ɥ쥹 */
#define MPCSADR12  0xfff781c0 /* �ΰ�12���ϥ��ɥ쥹 */
#define MPCSADR13  0xfff781d0 /* �ΰ�13���ϥ��ɥ쥹 */
#define MPCSADR14  0xfff781e0 /* �ΰ�14���ϥ��ɥ쥹 */
#define MPCSADR15  0xfff781f0 /* �ΰ�15���ϥ��ɥ쥹 */

#define MPCEADR0   0xfff78104 /* �ΰ�0 ��λ���ɥ쥹 */
#define MPCEADR1   0xfff78114 /* �ΰ�1 ��λ���ɥ쥹 */
#define MPCEADR2   0xfff78124 /* �ΰ�2 ��λ���ɥ쥹 */
#define MPCEADR3   0xfff78134 /* �ΰ�3 ��λ���ɥ쥹 */
#define MPCEADR4   0xfff78144 /* �ΰ�4 ��λ���ɥ쥹 */
#define MPCEADR5   0xfff78154 /* �ΰ�5 ��λ���ɥ쥹 */
#define MPCEADR6   0xfff78164 /* �ΰ�6 ��λ���ɥ쥹 */
#define MPCEADR7   0xfff78174 /* �ΰ�7 ��λ���ɥ쥹 */
#define MPCEADR8   0xfff78184 /* �ΰ�8 ��λ���ɥ쥹 */
#define MPCEADR9   0xfff78194 /* �ΰ�9 ��λ���ɥ쥹 */
#define MPCEADR10  0xfff781a4 /* �ΰ�10��λ���ɥ쥹 */
#define MPCEADR11  0xfff781b4 /* �ΰ�11��λ���ɥ쥹 */
#define MPCEADR12  0xfff781c4 /* �ΰ�12��λ���ɥ쥹 */
#define MPCEADR13  0xfff781d4 /* �ΰ�13��λ���ɥ쥹 */
#define MPCEADR14  0xfff781e4 /* �ΰ�14��λ���ɥ쥹 */
#define MPCEADR15  0xfff781f4 /* �ΰ�15��λ���ɥ쥹 */

#define MPCACR0    0xfff78108 /* �ΰ�0 ������������ */
#define MPCACR1    0xfff78118 /* �ΰ�1 ������������ */
#define MPCACR2    0xfff78128 /* �ΰ�2 ������������ */
#define MPCACR3    0xfff78138 /* �ΰ�3 ������������ */
#define MPCACR4    0xfff78148 /* �ΰ�4 ������������ */
#define MPCACR5    0xfff78158 /* �ΰ�5 ������������ */
#define MPCACR6    0xfff78168 /* �ΰ�6 ������������ */
#define MPCACR7    0xfff78178 /* �ΰ�7 ������������ */
#define MPCACR8    0xfff78188 /* �ΰ�8 ������������ */
#define MPCACR9    0xfff78198 /* �ΰ�9 ������������ */
#define MPCACR10   0xfff781a8 /* �ΰ�10������������ */
#define MPCACR11   0xfff781b8 /* �ΰ�11������������ */
#define MPCACR12   0xfff781c8 /* �ΰ�12������������ */
#define MPCACR13   0xfff781d8 /* �ΰ�13������������ */
#define MPCACR14   0xfff781e8 /* �ΰ�14������������ */
#define MPCACR15   0xfff781f8 /* �ΰ�15������������ */

#define PAGE_SIZE 4
#define MPCADR_mpcsadr0     0x00
#define MPCADR_mpceadr0     0x04
#define MPCADR_mpcsadr1     0x10
#define MPCADR_mpceadr1     0x14
#define MPCADR_mpcsadr2     0x20
#define MPCADR_mpceadr2     0x24
#define MPCADR_mpcsadr3     0x30
#define MPCADR_mpceadr3     0x34
#define MPCADR_mpcsadr4     0x40
#define MPCADR_mpceadr4     0x44
#define MPCADR_mpcsadr5     0x50
#define MPCADR_mpceadr5     0x54
#define MPCADR_mpcsadr6     0x60
#define MPCADR_mpceadr6     0x64
#define MPCADR_mpcsadr7     0x70
#define MPCADR_mpceadr7     0x74
#define MPCADR_mpcsadr8     0x80
#define MPCADR_mpceadr8     0x84
#define MPCADR_mpcsadr9     0x90
#define MPCADR_mpceadr9     0x94
#define MPCADR_mpcsadr10    0xa0
#define MPCADR_mpceadr10    0xa4
#define MPCADR_mpcsadr11    0xb0
#define MPCADR_mpceadr11    0xb4
#define MPCADR_mpcsadr12    0xc0
#define MPCADR_mpceadr12    0xc4
#define MPCADR_mpcsadr13    0xd0
#define MPCADR_mpceadr13    0xd4
#define MPCADR_mpcsadr14    0xe0
#define MPCADR_mpceadr14    0xe4
#define MPCADR_mpcsadr15    0xf0
#define MPCADR_mpceadr15    0xf4

#define OMIT_PROBE_MEM_WRITE
#define OMIT_PROBE_MEM_READ
#define OMIT_PROBE_STACK

#ifndef TOPPERS_MACRO_ONLY

extern void target_mpu_initialize(void);
extern void target_mpu_exc_handler(void *p_excinf);
// �������㳰�¹Գ��ϻ������å������ϥ�ɥ�
extern void target_emulate_texrtn_handler(void *p_excinf);
// �������㳰�꥿����������å������ϥ�ɥ�
extern void target_emulate_ret_tex_handler(void *p_excinf);

#endif /* TOPPERS_MACRO_ONLY */
#endif /* TOPPERS_TARGET_MPU_H */
