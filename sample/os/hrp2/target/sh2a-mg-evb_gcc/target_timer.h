/*
 *  TOPPERS/HRP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      High Reliable system Profile Kernel
 *	
 *	Copyright (C) 2011 by Embedded and Real-Time Systems Laboratory
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
 *	�����ޥɥ饤�С�SH2AW�ѡ�
 */

#ifndef TOPPERS_TARGET_TIMER_H
#define TOPPERS_TARGET_TIMER_H

#include <sil.h>

/*
 *  CMT�ʥ���ڥ��ޥå������ޡ˴�Ϣ�Υ쥸����
 */
#define CM01STR 0xfffec000 /* CMT0, CMT1���ϥ쥸���� */
#define CMT0_STR 0x0001    /* CMT0�������� */
#define CMT1_STR 0x0002    /* CMT1�������� */
#define CM23STR 0xfffec010 /* CMT2, CMT3���ϥ쥸���� */
#define CMT2_STR 0x0001    /* CMT2�������� */
#define CMT3_STR 0x0002    /* CMT3�������� */

#define CMT0CR 0xfffec002 /* CMT0����쥸���� */
#define CMT1CR 0xfffec008 /* CMT1����쥸���� */
#define CMT2CR 0xfffec012 /* CMT2����쥸���� */
#define CMT3CR 0xfffec018 /* CMT3����쥸���� */
#define CMCR_CMIE 0x0040  /* ����ߵ��ġʥӥåȤ�0���ȶػߡ� */
/*
 *	ʬ���� /8,/32,/128,/512 �Τ����줫������
 */
#define CMSR_CKS_DIV8  0x0000U
#define CMSR_CKS_DIV32  0x0001U
#define CMSR_CKS_DIV128  0x0002U
#define CMSR_CKS_DIV512  0x0003U

#define CMT0CNT 0xfffec004 /* CMT0������ */
#define CMT1CNT 0xfffec00a /* CMT1������ */
#define CMT2CNT 0xfffec014 /* CMT2������ */
#define CMT3CNT 0xfffec01a /* CMT3������ */

#define CMT0CMSE 0xfffec006 /* CMT0����ڥ��ޥå�����쥸���� */
#define CMT1CMSE 0xfffec00c /* CMT1����ڥ��ޥå�����쥸���� */
#define CMT2CMSE 0xfffec016 /* CMT2����ڥ��ޥå�����쥸���� */
#define CMT3CMSE 0xfffec01c /* CMT3����ڥ��ޥå�����쥸���� */

#define INTNO_CMT0 142 /* CMT0������ֹ� */
#define INTNO_CMT1 143 /* CMT1������ֹ� */
#define INTNO_CMT2 144 /* CMT2������ֹ� */
#define INTNO_CMT3 145 /* CMT3������ֹ� */

/*
 *  CMT0����Ѥ���
 */

/*
 *	�������ͤ�����ɽ���ȥߥ���ñ�̤Ȥ��Ѵ�
 *	1msec������Υ���å�������ȿ�
 *	���ߤ����ꡧ
 *	  f(CPU)��160MHz
 *	  f(PBA)��40MHz(f(CPU)��4ʬ��)
 *	  CMT�Υ�����ȥ�������32ʬ��
 */
#define TIMER_CLOCK ((40000000/32) / 1000)

/*
 *	�����޳���ߥϥ�ɥ���Ͽ�Τ�������
 */
#define INHNO_TIMER 	INTNO_CMT0    /* ����ߥϥ�ɥ��ֹ� */
#define INTNO_TIMER 	INTNO_CMT0    /* ������ֹ� */
#define INTPRI_TIMER	(-6)		  /* �����ͥ���� */
#define INTATR_TIMER	0U			  /* �����°�� */


#ifndef TOPPERS_TARGET_SUPPORT_OVRHDR
#define TOPPERS_TARGET_SUPPORT_OVRHDR
#endif /* TOPPERS_TARGET_SUPPORT_OVRHDR */

#ifdef TOPPERS_TARGET_SUPPORT_OVRHDR
/*
 *  CMT1����Ѥ���
 */

/*
 *	�����޳���ߥϥ�ɥ���Ͽ�Τ�������
 */
#define INHNO_OVRTIMER 	INTNO_CMT1    /* ����ߥϥ�ɥ��ֹ� */
#define INTNO_OVRTIMER 	INTNO_CMT1    /* ������ֹ� */
#define INTPRI_OVRTIMER	(-7)		  /* �����ͥ���� */
#define INTATR_OVRTIMER	0U			  /* �����°�� */

#endif /* TOPPERS_TARGET_SUPPORT_OVRHDR */

#ifndef TOPPERS_MACRO_ONLY

/*
 *	�������ͤ�����ɽ���η�
 */
typedef uint32_t	CLOCK;

/*
 *	�������ͤ�����ɽ���ȥߥ��á�����ñ�̤Ȥ��Ѵ�
 *
 */
#define TO_CLOCK(nume, deno)	((CLOCK)(TIMER_CLOCK * (nume) / (deno)))
#define TO_USEC(clock)			(((SYSUTM) clock) * 1000U / TIMER_CLOCK)

/*
 *	����Ǥ������Υ����޼�����ñ�̤�����ɽ����
 */
#define MAX_CLOCK	 ((CLOCK) 0xffffU)

/*
 *	�����ޤε�ư����
 *
 *	�����ޤ�������������Ū�ʥ����޳�����׵��ȯ�������롥
 */
extern void target_timer_initialize(intptr_t exinf);

/*
 *	�����ޤ���߽���
 *
 *	�����ޤ�ư�����ߤ����롥
 */
extern void target_timer_terminate(intptr_t exinf);

/*
 *	�����ޤθ����ͤ��ɽФ�
 */
Inline CLOCK
target_timer_get_current(void)
{
	return (CLOCK)(sil_reh_mem((void*)CMT0CNT));
}

/*
 *	�����޳�����׵�Υ����å�
 */
Inline bool_t
target_timer_probe_int(void)
{
    return (x_probe_int(INTNO_TIMER));
}

/*
 *	�����޳���ߥϥ�ɥ�
 */
extern void target_timer_handler(void);

#ifdef TOPPERS_TARGET_SUPPORT_OVRHDR
/*
 *	�������ͤ�����ɽ���ȥޥ�������ñ�̤Ȥ��Ѵ�
 *	1��sec������Υ���å�������ȿ�
 *	���ߤ����ꡧ
 *	  f(CPU)��160MHz
 *	  f(PBA)��40MHz(f(CPU)��4ʬ��)
 *	  CMT�Υ�����ȥ�������512ʬ��
 */
// #define OVRTIMER_CLOCK ((40000000/DIV) / 1000000)
#define OVRTIMER_CLOCK(usec) ((40 * usec) / 512)
#define OVRTIMER_USEC(clock) ((512 * clock) / 40)

/*
 *	�����Х�󥿥��ޤν��������
 *
 *	�����ޤ��������롥
 */
extern void target_ovrtimer_initialize(intptr_t exinf);

/*
 *	�����Х�󥿥��ޤν�λ����
 *
 *	�����ޤ�ư���λ���롥
 */
extern void target_ovrtimer_terminate(intptr_t exinf);

/*
 *	�����Х�󥿥��ޤε�ư����
 *
 *	�����ޤ�ư���롥
 */
extern void target_ovrtimer_start(OVRTIM ovrtim);

/*
 *	�����Х�󥿥��ޤ���߽���
 *
 *	�����ޤ�ư�����ߤ����롥
 */
extern OVRTIM target_ovrtimer_stop(void);

/*
 *	�����Х�󥿥��ޤθ����ͤ��ɽФ�
 */
extern OVRTIM target_ovrtimer_get_current(void);

/*
 *	�����Х�󥿥��޳���ߥϥ�ɥ�
 */
extern void target_ovrtimer_handler(void);

/*
 *  �����Х��ϥ�ɥ鵯ư�롼����
 */
extern void	call_ovrhdr(void);

#endif /* TOPPERS_TARGET_SUPPORT_OVRHDR */

#endif /* TOPPERS_MACRO_ONLY */
#endif /* TOPPERS_TARGET_TIMER_H */
