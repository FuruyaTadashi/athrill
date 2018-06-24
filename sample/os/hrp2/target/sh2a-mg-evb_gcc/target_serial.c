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
 *	���ꥢ��I/O�ǥХ�����SIO�˥ɥ饤�С�SH2A-MG-EVB�ѡ�
 *	SCI0 �����
 */

#include "kernel/kernel_impl.h"
#include <t_syslog.h>
#include <sil.h>
#include "target_serial.h"

const SIOPINIB siopinib_table[TNUM_SCI_PORT] = {
#if TNUM_SCI_PORT > 0
    {
        (void *)(SCI0_BASE + OFFSET_SCI_CR),     /* ����쥸���� */
        (void *)(SCI0_BASE + OFFSET_SCI_MD),     /* �⡼�ɥ쥸���� */
        (void *)(SCI0_BASE + OFFSET_SCI_EMD),    /* ��ĥ�⡼�ɥ쥸���� */
        (void *)(SCI0_BASE + OFFSET_SCI_BR),     /* �ӥåȥ졼�ȥ쥸���� */
        (void *)(SCI0_BASE + OFFSET_SCI_TB),     /* �����Хåե��쥸���� */
        (void *)(SCI0_BASE + OFFSET_SCI_RB),     /* �����Хåե��쥸���� */
        (void *)(SCI0_BASE + OFFSET_SCI_SR),     /* ���ơ������쥸���� */
        (void *)(PIO_PA10CR),  /* RXDü�ҤΥݡ�������쥸���� */
        (void *)(PIO_PA11CR),  /* TXDü�ҤΥݡ�������쥸���� */
        (void *)(PIO_PA12CR),  /* SCKü�ҤΥݡ�������쥸���� */
        (void *)(PIO_PAIN),    /* RXDü�ҤΥݡ������ϥ쥸���� */
        (10),          /* RXD���б�����PIO���ֹ桧A/B�θ�ο��� */
        (INTNO_SCI0_RXF), /* �����Хåե��ե�γ�����ֹ� */
        (INTNO_SCI0_TXC), /* ������λ�γ�����ֹ� */
    },
#endif /* TNUM_SCI_PORT > 0 */
#if TNUM_SCI_PORT > 1
    {
        (void *)(SCI1_BASE + OFFSET_SCI_CR),     /* ����쥸���� */
        (void *)(SCI1_BASE + OFFSET_SCI_MD),     /* �⡼�ɥ쥸���� */
        (void *)(SCI1_BASE + OFFSET_SCI_EMD),    /* ��ĥ�⡼�ɥ쥸���� */
        (void *)(SCI1_BASE + OFFSET_SCI_BR),     /* �ӥåȥ졼�ȥ쥸���� */
        (void *)(SCI1_BASE + OFFSET_SCI_TB),     /* �����Хåե��쥸���� */
        (void *)(SCI1_BASE + OFFSET_SCI_RB),     /* �����Хåե��쥸���� */
        (void *)(SCI1_BASE + OFFSET_SCI_SR),     /* ���ơ������쥸���� */
        (void *)(PIO_PA13CR),  /* RXDü�ҤΥݡ�������쥸���� */
        (void *)(PIO_PA14CR),  /* TXDü�ҤΥݡ�������쥸���� */
        (void *)(PIO_PA15CR),  /* SCKü�ҤΥݡ�������쥸���� */
        (void *)(PIO_PAIN),    /* RXDü�ҤΥݡ������ϥ쥸���� */
        (13),          /* RXD���б�����PIO���ֹ桧A/B�θ�ο��� */
        (INTNO_SCI1_RXF), /* �����Хåե��ե�γ�����ֹ� */
        (INTNO_SCI1_TXC), /* ������λ�γ�����ֹ� */
    },
#endif /* TNUM_SCI_PORT > 1 */
#if TNUM_SCI_PORT > 2
    {
        (void *)(SCI2_BASE + OFFSET_SCI_CR),     /* ����쥸���� */
        (void *)(SCI2_BASE + OFFSET_SCI_MD),     /* �⡼�ɥ쥸���� */
        (void *)(SCI2_BASE + OFFSET_SCI_EMD),    /* ��ĥ�⡼�ɥ쥸���� */
        (void *)(SCI2_BASE + OFFSET_SCI_BR),     /* �ӥåȥ졼�ȥ쥸���� */
        (void *)(SCI2_BASE + OFFSET_SCI_TB),     /* �����Хåե��쥸���� */
        (void *)(SCI2_BASE + OFFSET_SCI_RB),     /* �����Хåե��쥸���� */
        (void *)(SCI2_BASE + OFFSET_SCI_SR),     /* ���ơ������쥸���� */
        (void *)(PIO_PB02CR),  /* RXDü�ҤΥݡ�������쥸���� */
        (void *)(PIO_PB03CR),  /* TXDü�ҤΥݡ�������쥸���� */
        (void *)(PIO_PB04CR),  /* SCKü�ҤΥݡ�������쥸���� */
        (void *)(PIO_PBIN),    /* RXDü�ҤΥݡ������ϥ쥸���� */
        (2),          /* RXD���б�����PIO���ֹ桧A/B�θ�ο��� */
        (INTNO_SCI2_RXF), /* �����Хåե��ե�γ�����ֹ� */
        (INTNO_SCI2_TXC), /* ������λ�γ�����ֹ� */
    },
#endif /* TNUM_SCI_PORT > 2 */
#if TNUM_SCI_PORT > 3
    // PIO���ֹ�ϡ��ꥻ�åȸ������ 
    {
        (void *)(SCI3_BASE + OFFSET_SCI_CR),     /* ����쥸���� */
        (void *)(SCI3_BASE + OFFSET_SCI_MD),     /* �⡼�ɥ쥸���� */
        (void *)(SCI3_BASE + OFFSET_SCI_EMD),    /* ��ĥ�⡼�ɥ쥸���� */
        (void *)(SCI3_BASE + OFFSET_SCI_BR),     /* �ӥåȥ졼�ȥ쥸���� */
        (void *)(SCI3_BASE + OFFSET_SCI_TB),     /* �����Хåե��쥸���� */
        (void *)(SCI3_BASE + OFFSET_SCI_RB),     /* �����Хåե��쥸���� */
        (void *)(SCI3_BASE + OFFSET_SCI_SR),     /* ���ơ������쥸���� */
        (void *)(PIO_PA06CR),  /* RXDü�ҤΥݡ�������쥸���� */
        (void *)(PIO_PA07CR),  /* TXDü�ҤΥݡ�������쥸���� */
        (void *)(PIO_PA08CR),  /* SCKü�ҤΥݡ�������쥸���� */
        (void *)(PIO_PAIN),    /* RXDü�ҤΥݡ������ϥ쥸���� */
        (6),          /* RXD���б�����PIO���ֹ桧A/B�θ�ο��� */
        (INTNO_SCI3_RXF), /* �����Хåե��ե�γ�����ֹ� */
        (INTNO_SCI3_TXC), /* ������λ�γ�����ֹ� */
    },
#endif /* TNUM_SCI_PORT > 3 */
};

SIOPCB siopcb_table[TNUM_SCI_PORT];

/*
 *	SIO�ɥ饤�Фν����
 */
void
sio_initialize(intptr_t exinf)
{
    SIOPCB *p_siopcb;
    int8_t i;

    for(i = 0, p_siopcb = &(siopcb_table[0]); i < TNUM_SCI_PORT; i++, p_siopcb++){
        p_siopcb->p_siopinib = &(siopinib_table[i]);
    }
}

void
sio_hardware_initialize(const SIOPINIB *p_siopinib)
{
    /*
     *  �ݡ�������쥸��������������ϡ�
     */
    sil_wrb_mem((void *)PIO_PPR, PIO_PPR_UNPROTECT); /* �ץ�ƥ��Ȥβ�� */

    /* ���Ϥ���ġ��ݡ��ȵ�ǽ�ϼ��յ�ǽ���� */
    sil_wrh_mem(p_siopinib->rxdiocr, (PIO_CR_INE | PIO_CR_PSEL_IO));

    sil_wrb_mem((void *)PIO_PPR, 0); /* �ץ�ƥ��� */

    /*
     *  ��������ػ�
     */
    sil_wrb_mem(p_siopinib->sccr,
                (sil_reb_mem(p_siopinib->sccr) & ~(SCI_CR_TE | SCI_CR_RE)));

    /*
     *  ����å����� 
     */
    sil_wrb_mem(p_siopinib->sccr,
                ((sil_reb_mem(p_siopinib->sccr) & ~(SCI_CR_CKS_MASK)) | (SCI_CR_CKS)));

    /*
     *  �⡼�ɥ쥸����������
     *  Ĵ��Ʊ������
     *  �ǡ���Ĺ8�ӥåȡ��ѥ�ƥ��ʤ���1���ȥåץӥåȡ�
     *  ������ȥ�������ʬ���ʤ�
     */
    sil_wrb_mem(p_siopinib->scmd,
                (sil_reb_mem(p_siopinib->scmd) & 
                 ~(SCI_MD_SMS | SCI_MD_SDLS | SCI_MD_PE | SCI_MD_TSTLS | SCI_MD_SCSS_MASK)));
    sil_wrb_mem(p_siopinib->scmd,
                (sil_reb_mem(p_siopinib->scmd) | SCI_MD_SCSS_DIV0));

    /*
     *  �ӥåȥ졼�Ȥ����ꡧ38400
     */
    sil_wrb_mem(p_siopinib->scbr, CONVERT_BITRATE(38400));

    sil_dly_nse(40000);

    /*
     *  ����������ߤζػ�
     */
    sil_wrb_mem(p_siopinib->sccr,
                (sil_reb_mem(p_siopinib->sccr) & ~(SCI_CR_TIE)));
    sil_wrb_mem(p_siopinib->sccr,
                (sil_reb_mem(p_siopinib->sccr) & ~(SCI_CR_TEIE | SCI_CR_RIE)));

    /*
     *  �ݡ�������쥸����������ʽ��ϡ�
     */
    sil_wrb_mem((void *)PIO_PPR, PIO_PPR_UNPROTECT); /* �ץ�ƥ��Ȥβ�� */

    /* 
     *  ���Ϥ����ػߤ����塤
     *  �ݡ��ȵ�ǽ��SCI��ǽ���Ϥ����ꤷ��Ʊ���˽��ϵ���
     *  �̡������ꤹ�뤳�ȤϤǤ��ʤ�
     */
    sil_wrh_mem(p_siopinib->txdiocr, (~(PIO_CR_OUTE) & PIO_CR_PSEL_IO));
    sil_wrh_mem(p_siopinib->txdiocr, 
                (sil_reb_mem(p_siopinib->txdiocr) | (PIO_CR_OUTE | PIO_CR_PSEL_SCI)));

    sil_wrb_mem((void *)PIO_PPR, 0); /* �ץ�ƥ��� */

    /*
     *  RXDü�Ҥ�high�Ǥ��뤳�Ȥ�����å�
     */
    assert((sil_reh_mem(p_siopinib->rxdioin) & (1 << p_siopinib->rxpio)) != 0);

    /*
     *  �����������
     */
    sil_wrb_mem(p_siopinib->sccr,
                (sil_reb_mem(p_siopinib->sccr) | (SCI_CR_TE | SCI_CR_RE)));

}

Inline void
enable_int_send(const SIOPINIB *p_siopinib)
{
    sil_wrb_mem(p_siopinib->sccr,
                (sil_reb_mem(p_siopinib->sccr) | (SCI_CR_TEIE)));
}

Inline void
enable_int_receive(const SIOPINIB *p_siopinib)
{
    sil_wrb_mem(p_siopinib->sccr,
                (sil_reb_mem(p_siopinib->sccr) | (SCI_CR_RIE)));
}

Inline void
disable_int_send(const SIOPINIB *p_siopinib)
{
    sil_wrb_mem(p_siopinib->sccr,
                (sil_reb_mem(p_siopinib->sccr) & ~(SCI_CR_TEIE)));
}

Inline void
disable_int_receive(const SIOPINIB *p_siopinib)
{
    sil_wrb_mem(p_siopinib->sccr,
                (sil_reb_mem(p_siopinib->sccr) & ~(SCI_CR_RIE)));
}

Inline bool_t
sio_ready_send_char(const SIOPINIB *p_siopinib)
{
    if((sil_reb_mem(p_siopinib->scsr) & SCI_SR_TBEF) != 0){
        return true;
    } else {
        return false;
    }
}

Inline bool_t
sio_ready_receive_char(const SIOPINIB *p_siopinib)
{
    if((sil_reb_mem(p_siopinib->scsr) & SCI_SR_RBFF) != 0){
        return true;
    } else {
        return false;
    }
}

/*
 *	���ꥢ��I/O�ݡ��ȤΥ����ץ�
 */
SIOPCB *
sio_opn_por(ID siopid, intptr_t exinf)
{
	SIOPCB *p_siopcb = &(siopcb_table[siopid - 1]);
	const SIOPINIB *p_siopinib = p_siopcb->p_siopinib;

    /*
     *  ��ĥ�������¸����
     *  ����ϡ�������Хå��롼������Ϥ������Ȥʤ�
     */
    p_siopcb->exinf = exinf;

    /*
	 *	���ꥢ��I/O����ߤ�ޥ������롥
	 */
	dis_int(p_siopinib->intno_rx);
	dis_int(p_siopinib->intno_tx);

    if(!(p_siopcb->initialized_flag)){
        p_siopcb->initialized_flag = true;

        sio_hardware_initialize(p_siopinib);
    }

    /*
	 *	���ꥢ��I/O����ߤ���Ĥ��롥
	 */
	ena_int(p_siopinib->intno_rx);
	ena_int(p_siopinib->intno_tx);

	return(p_siopcb);
}

/*
 *	���ꥢ��I/O�ݡ��ȤΥ�����
 */
void
sio_cls_por(SIOPCB *p_siopcb)
{
    const SIOPINIB *p_siopinib = p_siopcb->p_siopinib;

    /*
     *  ��������ػ�
     */
    sil_wrb_mem(p_siopinib->sccr,
                (sil_reb_mem(p_siopinib->sccr) & ~(SCI_CR_TE | SCI_CR_RE)));

    /*
     *  ����������ߤ�ػ�
     */
    sil_wrb_mem(p_siopinib->sccr,
                (sil_reb_mem(p_siopinib->sccr) & ~(SCI_CR_TIE | SCI_CR_RIE)));

	/*
	 *	���ꥢ��I/O����ߤ�ޥ������롥
	 */
	dis_int(p_siopinib->intno_rx);
	dis_int(p_siopinib->intno_tx);
}

/*
 *	SIO�γ���ߥϥ�ɥ�
 */
void
sio_tx_isr(intptr_t exinf)
{
    /*
     *  exinf�ˤϡ�����ߤ�ȯ����������ͥ��ֹ椬���äƤ���Τǡ�
     *  �������顤�����ץ��������¸������ĥ������������
     *  ������Хå��롼����ΰ����Ȥ���
     */
    exinf = (siopcb_table[exinf - 1]).exinf;

	sio_irdy_snd(exinf);
}


/*
 *	SIO�γ���ߥϥ�ɥ�
 */
void
sio_rx_isr(intptr_t exinf)
{
    /*
     *  ���å��ȥꥬ�γ�����װ��򥯥ꥢ
     */
    x_clear_int(siopinib_table[exinf - 1].intno_rx);
    /*
     *  exinf�ˤϡ�����ߤ�ȯ����������ͥ��ֹ椬���äƤ���Τǡ�
     *  �������顤�����ץ��������¸������ĥ������������
     *  ������Хå��롼����ΰ����Ȥ���
     */
    exinf = (siopcb_table[exinf - 1]).exinf;

	sio_irdy_rcv(exinf);
}

/*
 *	���ꥢ��I/O�ݡ��Ȥؤ�ʸ������
 */
bool_t
sio_snd_chr(SIOPCB *p_siopcb, char c)
{
    const SIOPINIB *p_siopinib = p_siopcb->p_siopinib;

    if(sio_ready_send_char(p_siopinib)){
        sil_wrb_mem(p_siopinib->sctb, (uint8_t)c);

        return true;
    } else {
        return false;
    }
}

/*
 *	���ꥢ��I/O�ݡ��Ȥ����ʸ������
 */
int_t
sio_rcv_chr(SIOPCB *p_siopcb)
{
    const SIOPINIB *p_siopinib = p_siopcb->p_siopinib;

    if(sio_ready_receive_char(p_siopinib)){
        return (int_t)sil_reb_mem(p_siopinib->scrb);
    }

    return 0;
}

/*
 *	���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ε���
 */
void
sio_ena_cbr(SIOPCB *p_siopcb, uint_t cbrtn)
{
    const SIOPINIB *p_siopinib = p_siopcb->p_siopinib;

    switch(cbrtn){
        case SIO_RDY_RCV:
            /*
             *	��������ߤΥޥ�����������
             */
            enable_int_receive(p_siopinib);
            break;
        case SIO_RDY_SND:
            /*
             *	��������ߤΥޥ�����������
             */
            enable_int_send(p_siopinib);
            break;
        default:
            break;
    }
}

/*
 *	���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ζػ�
 */
void
sio_dis_cbr(SIOPCB *p_siopcb, uint_t cbrtn)
{
    const SIOPINIB *p_siopinib = p_siopcb->p_siopinib;

    switch(cbrtn){
        case SIO_RDY_RCV:
            /*
             *	��������ߤ�ޥ�������
             */
            disable_int_receive(p_siopinib);
            break;
        case SIO_RDY_SND:
            /*
             *	��������ߤ�ޥ�������
             */
            disable_int_send(p_siopinib);
            break;
        default:
            break;
    }
}

