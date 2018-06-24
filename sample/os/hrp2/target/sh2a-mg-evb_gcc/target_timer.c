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
 *	
 *	CMT0�����
 */

#include "kernel_impl.h"
#include <sil.h>
#include "target_timer.h"
#include "time_event.h"
#include "overrun.h"

/*
 *	�����ޤε�ư����
 */
void
target_timer_initialize(intptr_t exinf)
{
	CLOCK	 cyc = TO_CLOCK(TIC_NUME, TIC_DENO) - 1;

	/*
	 *	�����޼��������ꤷ�������ޤ�ư��򳫻Ϥ��롥
	 */
	/* CMT0��� */
	sil_wrh_mem((void *)CM01STR,
				(sil_reh_mem((void *)CM01STR) & ~CMT0_STR));

	/* �����޾���ͤΥ����å� */
	assert(cyc <= MAX_CLOCK);

	/* ʬ�������ꡢ����ߵ��� */
	sil_wrh_mem((void *)CMT0CR, (CMSR_CKS_DIV32	| CMCR_CMIE));

	/* ����ڥ��ޥå�������Ȥ򥻥å� */
	sil_wrh_mem((void *)CMT0CMSE, (uint16_t)cyc);
	
    /* �����󥿤�ꥻ�å� */
	sil_wrh_mem((void *)CMT0CNT, (uint16_t)0U);

	/* ������׵�򥯥ꥢ */
    x_clear_int(INTNO_TIMER);
	
    /* CMT0�������� */
	sil_wrh_mem((void*)CM01STR,
				(sil_reh_mem((void*)CM01STR) | CMT0_STR));

}

/*
 *	�����ޤ���߽���
 */
void
target_timer_terminate(intptr_t exinf)
{
	/* �����ޤ���� */
	sil_wrh_mem((void *)CM01STR,
				(sil_reh_mem((void *)CM01STR) & ~CMT0_STR));
	
	/* ������׵�򥯥ꥢ */
    x_clear_int(INTNO_TIMER);

}

/*
 *	�����޳���ߥϥ�ɥ�
 */
void
target_timer_handler(void)
{
	/* ������׵�򥯥ꥢ */
    x_clear_int(INTNO_TIMER);

	i_begin_int(INTNO_TIMER);
	signal_time();					  /* ������ƥ��å��ζ��� */
	i_end_int(INTNO_TIMER);
}

#ifdef TOPPERS_TARGET_SUPPORT_OVRHDR
/*
 *	�����Х�󥿥��ޤν��������
 *
 *	�����ޤ��������롥
 */
void
target_ovrtimer_initialize(intptr_t exinf)
{
	/*
	 *	�����޼��������ꤹ�롥
	 */
	/* CMT1��� */
	sil_wrh_mem((void *)CM01STR,
				(sil_reh_mem((void *)CM01STR) & ~CMT1_STR));

	/* ʬ�������ꡢ����ߵ��� */
	sil_wrh_mem((void *)CMT1CR, (CMSR_CKS_DIV512 | CMCR_CMIE));

}

/*
 *	�����Х�󥿥��ޤν�λ����
 *
 *	�����ޤ�ư���λ���롥
 */
void
target_ovrtimer_terminate(intptr_t exinf)
{
	/* �����ޤ���� */
	sil_wrh_mem((void *)CM01STR,
				(sil_reh_mem((void *)CM01STR) & ~CMT1_STR));
	
	/* ������׵�򥯥ꥢ */
    x_clear_int(INTNO_TIMER);

}

/*
 *	�����Х�󥿥��ޤε�ư����
 *
 *	�����ޤ�ư���롥
 */
void
target_ovrtimer_start(OVRTIM ovrtim)
{
	CLOCK	 cyc = OVRTIMER_CLOCK(ovrtim) - 1;

	/*
	 *	�����޼��������ꤷ�������ޤ�ư��򳫻Ϥ��롥
	 */
	/* �����޾���ͤΥ����å� */
	assert(cyc <= MAX_CLOCK);

	/* ����ڥ��ޥå�������Ȥ򥻥å� */
	sil_wrh_mem((void *)CMT1CMSE, (uint16_t)cyc);
	
    /* �����󥿤�ꥻ�å� */
	sil_wrh_mem((void *)CMT1CNT, (uint16_t)0U);

	/* ������׵�򥯥ꥢ */
    x_clear_int(INTNO_TIMER);
	
    /* CMT1�������� */
	sil_wrh_mem((void*)CM01STR,
				(sil_reh_mem((void*)CM01STR) | CMT1_STR));

}

/*
 *	�����Х�󥿥��ޤ���߽���
 *
 *	�����ޤ�ư�����ߤ����롥
 */
OVRTIM
target_ovrtimer_stop(void)
{
    OVRTIM rest;

	/* �����ޤ���� */
	sil_wrh_mem((void *)CM01STR,
				(sil_reh_mem((void *)CM01STR) & ~CMT1_STR));
	
	/* ������׵�򥯥ꥢ */
    x_clear_int(INTNO_TIMER);

	rest = ((OVRTIM)sil_reh_mem((void*)CMT1CMSE) - (OVRTIM)sil_reh_mem((void*)CMT1CNT));

    if(rest < 0){
        return 1;
    } else {
        return (OVRTIMER_USEC(rest + 1));
    }
}

/*
 *	�����Х�󥿥��ޤλĤ���֤��ɽФ�
 */
OVRTIM
target_ovrtimer_get_current(void)
{
    OVRTIM rest;

	rest = ((OVRTIM)sil_reh_mem((void*)CMT1CMSE) - (OVRTIM)sil_reh_mem((void*)CMT1CNT));

    if(rest < 0){
        return 0;
    } else {
        return (OVRTIMER_USEC(rest + 1));
    }
}

/*
 *	�����Х�󥿥��޳���ߥϥ�ɥ�
 */
void
target_ovrtimer_handler(void)
{
	i_begin_int(INTNO_OVRTIMER);
	call_ovrhdr();
	i_end_int(INTNO_OVRTIMER);
}

#endif /* TOPPERS_TARGET_SUPPORT_OVRHDR */


