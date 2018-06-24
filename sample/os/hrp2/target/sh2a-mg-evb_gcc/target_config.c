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
 *	�������åȰ�¸�⥸�塼���SH2A-MG-EVB�ѡ�
 */

#include "kernel_impl.h"
#include <sil.h>
#include "sh72aw.h"
#include "target_serial.h"
#include "task.h"
#include "memory.h"

/*
 *	�������åȰ�¸�ν����
 */
void
target_initialize(void)
{
	/*
	 *	�ץ��å���¸�ν����
	 */
	prc_initialize();

    /*
     *  MPU�ν����
     */
    target_mpu_initialize();

	/*
	 *  ���٥�����ѤΥ��ꥢ�륳��ȥ���ν����
	 */
    target_fput_initialize();
}

/*
 *	�������åȰ�¸�ν�λ����
 */
void
target_exit(void)
{
	/*
	 *	�ץ��å���¸�ν�λ����
	 */
	prc_exit();

	/*
	 *	��ȯ�Ķ���¸�ν�λ����
     *	�äˤʤ�
	 */
    while(1);

	/*
	 * �����ˤ���ʤ�
	 */
	while(1);
}

/*
 *  ���٥�����ѥ��ꥢ��ݡ��Ȥν����
 */
void
target_fput_initialize(void)
{
    SIOPCB *p_siopcb = &(siopcb_table[TARGET_PUTC_PORTID - 1]);
    const SIOPINIB *p_siopinib = &(siopinib_table[TARGET_PUTC_PORTID - 1]);

    if(!(p_siopcb->initialized_flag)){
        p_siopcb->initialized_flag = true;

        sio_hardware_initialize(p_siopinib);
    }
}

/*
 *	�����ƥ�������٥���ϤΤ����ʸ������
 */
Inline void
sio_send_char_pol(char c)
{
    const SIOPINIB *p_siopinib = &(siopinib_table[TARGET_PUTC_PORTID - 1]);
    SIL_PRE_LOC;

    /*
     *  �����Хåե��������ޤ��Ԥ�
     */
    while((sil_reb_mem(p_siopinib->scsr) & SCI_SR_TBEF) == 0);

    /*
     *  ¾�ν���ñ�̤������Хåե���Ȥ��ʤ��褦�ˡ�
     *  ����ߤ�ػߤ���
     */
    SIL_LOC_INT();
    
    /*
     *  �����Хåե���ʸ����񤭹���
     */
    sil_wrb_mem(p_siopinib->sctb, (uint8_t)c);

    /*
     *  ����߶ػߤ���
     */
    SIL_UNL_INT();
}

void
target_fput_log(char c)
{
	if (c == '\n') {
		sio_send_char_pol('\r');
	}
    sio_send_char_pol(c);
}

/*
 *	������׵�饤��°��������
 */
void
x_config_int(INTNO intno, ATR intatr, PRI intpri)
{
    uint16_t set_icr;

	assert(VALID_INTNO_CFGINT(intno));
	assert((-15 <= intpri) && (intpri <= TMAX_INTPRI));

	/*
	 *	��ö����ߤ�ػߤ���
	 */
	(void)x_disable_int(intno);

    /*
     *  �����ͥ���٤�����ȳ���ߵ���
     */
    set_icr = (intatr & TA_ENAINT)? INTC_PB_ICR_INTEN: 0U;
    intpri *= -1; // +-��ȿž
    set_icr |= ((uint16_t)intpri & INTC_PB_ICR_IPR_MASK);

    sil_wrh_mem((void *)(INTC_PB_ICR_BASE + (intno - INTC_PB_INTNO_BASE) * 2), set_icr);

}

/*
 *  �����ΰ褬�桼�������å��ΰ�˴ޤޤ�Ƥ��뤫�Υ����å�
 *
 *  ��Ƭ���Ϥ�base�ǥ�������size�Υ����ΰ褬��p_tcb�ǻ��ꤵ��륿����
 *  �Υ桼�������å��ΰ�˴ޤޤ�Ƥ������true�������Ǥʤ�����
 *  false���֤���
 *
 *  �����ΰ����Ƭ���Ϥ���桼�������å�����ޤǤ�Ĺ����
 *  �����ΰ�Υ����������礭�������ġ�
 *  �桼�������å��Υ��������⾮������С������ΰ�ϡ�
 *  �桼�������å����ϰ���Ǥ��롥
 *
 */
bool_t
within_ustack(const void *base, SIZE size, TCB *p_tcb)
{
    SIZE stk_bottom = (SIZE)(p_tcb->p_tinib->tskinictxb.stk_bottom);
    SIZE len = stk_bottom - (SIZE)base;

    return ((SIZE)base < stk_bottom
            && len >= size
            && len <= (SIZE)(p_tcb->p_tinib->tskinictxb.stksz));
}

/*
 *  �桼���������Υ������㳰�����ƤӽФ�����
 *  ���Ѥ��륹���å���������­��ʤ�����
 */
bool_t
i_check_tex_runtsk()
{
    SIZE ustk_top = (SIZE)(p_runtsk->tskctxb.usp);

    if(!PROBE_STACK((void *)(ustk_top - USRTEX_STKSZ), 
                USRTEX_STKSZ)){
        return (true);
    }

    return (false);
}  

