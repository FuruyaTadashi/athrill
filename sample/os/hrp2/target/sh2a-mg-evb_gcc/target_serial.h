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
 */

#ifndef TOPPERS_TARGET_SERIAL_H
#define TOPPERS_TARGET_SERIAL_H

/*
 *  ���ꥢ��I/O�ݡ��Ƚ�����֥�å������
 *  �쥸���������Ϥȳ�����ֹ�
 */
typedef struct sio_port_initialization_block {
    void *sccr;     /* ����쥸���� */
    void *scmd;     /* �⡼�ɥ쥸���� */
    void *scemd;    /* ��ĥ�⡼�ɥ쥸���� */
    void *scbr;     /* �ӥåȥ졼�ȥ쥸���� */
    void *sctb;     /* �����Хåե��쥸���� */
    void *scrb;     /* �����Хåե��쥸���� */
    void *scsr;     /* ���ơ������쥸���� */
    void *rxdiocr;  /* RXDü�ҤΥݡ�������쥸���� */
    void *txdiocr;  /* TXDü�ҤΥݡ�������쥸���� */
    void *sckiocr;  /* SCKü�ҤΥݡ�������쥸���� */
    void *rxdioin;  /* RXDü�ҤΥݡ������ϥ쥸���� */
    uint8_t rxpio;  /* RXD���б�����PIO���ֹ桧A/B�θ�ο��� */
    INTNO intno_rx; /* �����Хåե��ե�γ�����ֹ� */
    INTNO intno_tx; /* �����Хåե�����ץƥ��γ�����ֹ� */
} SIOPINIB;

/*
 *  ���ꥢ��I/O�ݡ��ȴ����֥�å������
 */
typedef struct sio_port_control_block{
    const SIOPINIB *p_siopinib; /* ���ꥢ��I/O�ݡ��Ƚ�����֥�å� */
    intptr_t exinf;             /* ��ĥ���󡤤��ʤ�����������å����¸���Υ��ꥢ��ݡ��ȴ����֥�å���SPCB�ˤؤΥݥ��� */
    bool_t initialized_flag;    /* �ϡ��ɥ������ν�����򤷤����� */
}
SIOPCB;

#define TNUM_SCI_PORT 4 /* SCI�Υ���ͥ�� */

/*
 *  �쥸������Ϣ
 */

/*
 *  �ƥ���ͥ�Υ١������ɥ쥹
 */
#define SCI0_BASE 0xff610000
#define SCI1_BASE 0xff610010
#define SCI2_BASE 0xff610020
#define SCI3_BASE 0xff610030

/*
 *  �ƥ쥸�����Υ��ե��åȤ�������
 */
#define OFFSET_SCI_CR 0x00000002 /* ����쥸���� */
#define SCI_CR_TIE  0x80 /* �����Хåե�����ץƥ�����ߵ��ĥӥå� */
#define SCI_CR_RIE  0x40 /* �����Хåե��ե����ߵ��ĥӥå� */
#define SCI_CR_TE   0x20 /* �������ĥӥå� */
#define SCI_CR_RE   0x10 /* �������ĥӥå� */
#define SCI_CR_TEIE 0x04 /* ������λ����ߵ��ĥӥå� */
#define SCI_CR_CKS  0x00 /* ����å�����ӥåȡ���¢�ܡ��졼�ȥ����ͥ졼�����Ѥǡ�SCKü�Ҥ�PIO */
#define SCI_CR_CKS_MASK  0x03 /* ����å�����ӥåȤΥޥ��� */

#define OFFSET_SCI_MD 0x00000000 /* �⡼�ɥ쥸���� */
#define SCI_MD_SMS   0x80 /* ����å�Ʊ���������ΥӥåȤ�0�Ǥ�����ϡ�Ĵ��Ʊ���� */
#define SCI_MD_SDLS  0x40 /* �ǡ���Ĺ7�ӥåȡ����ΥӥåȤ�0�Ǥ�����ϡ�8�ӥå� */
#define SCI_MD_PE    0x20 /* �ѥ�ƥ����ꡧ���ΥӥåȤ�0�Ǥ�����ϡ��ѥ�ƥ��ʤ� */
#define SCI_MD_OES   0x10 /* ��ѥ�ƥ������ΥӥåȤ�0�Ǥ�����ϡ����ѥ�ƥ� */
#define SCI_MD_TSTLS 0x08 /* 2���ȥåץӥåȡ����ΥӥåȤ�0�Ǥ�����ϡ�1���ȥåץӥå� */
#define SCI_MD_SCSS_DIV0  0x00 /* ������ȥ���������ӥåȡ����յ�ǽ����å�A��ʬ���ʤ� */
#define SCI_MD_SCSS_DIV4  0x01 /* ������ȥ���������ӥåȡ����յ�ǽ����å�A��4ʬ�� */
#define SCI_MD_SCSS_DIV16 0x02 /* ������ȥ���������ӥåȡ����յ�ǽ����å�A��16ʬ�� */
#define SCI_MD_SCSS_DIV64 0x03 /* ������ȥ���������ӥåȡ����յ�ǽ����å�A��64ʬ�� */
#define SCI_MD_SCSS_MASK 0x03 /* ������ȥ���������ӥåȤΥޥ��� */

#define OFFSET_SCI_EMD 0x00000008 /* ��ĥ�⡼�ɥ쥸���� */
#define SCI_EMD_SDIR  0x08 /* MSB�ե������ȡ����ΥӥåȤ�0�Ǥ�����ϡ�LSB�ե������� */
#define SCI_EMD_CKPOS 0x02 /* ����ȿž���롧���ΥӥåȤ�0�Ǥ�����ϡ����ʤ� */
#define SCI_EMD_CKPHS 0x01 /* �����Ⱦ���٤餻�롧���ΥӥåȤ�0�Ǥ�����ϡ��٤餻�ʤ� */

#define OFFSET_SCI_BR 0x00000001 /* �ӥåȥ졼�ȥ쥸���� */
#define OFFSET_SCI_TB 0x00000003 /* �����Хåե��쥸���� */
#define OFFSET_SCI_RB 0x00000005 /* �����Хåե��쥸���� */

#define OFFSET_SCI_SR 0x00000004 /* ���ơ������쥸���� */
#define SCI_SR_TBEF  0x80 /* �����Хåե�����ץƥ��ե饰 */
#define SCI_SR_RBFF  0x40 /* �����Хåե��ե�ե饰 */
#define SCI_SR_OREF  0x20 /* �����Х�󥨥顼�ե饰 */
#define SCI_SR_FREF  0x10 /* �ե졼�ߥ󥰥��顼�ե饰 */
#define SCI_SR_PERF  0x08 /* �ѥ�ƥ����顼�ե饰 */
#define SCI_SR_TSEF  0x04 /* �������եȥ쥸��������ץƥ��ե饰 */

/*
 *  ������Хå��롼����μ����ֹ�
 */
#define SIO_RDY_SND    1U        /* ������ǽ������Хå� */
#define SIO_RDY_RCV    2U        /* �������Υ�����Хå� */

/*
 *	SIO�γ���ߥϥ�ɥ�Υ٥����ֹ�
 */
#define INTNO_SCI0_RXE 312 /* SCI0�������顼����� */
#define INTNO_SCI0_RXF 313 /* SCI0�����Хåե��ե����� */
#define INTNO_SCI0_TXE 314 /* SCI0�����Хåե�����ץƥ������ */
#define INTNO_SCI0_TXC 315 /* SCI0������λ����� */
#define INTNO_SCI1_RXE 316 /* SCI1�������顼����� */
#define INTNO_SCI1_RXF 317 /* SCI1�����Хåե��ե����� */
#define INTNO_SCI1_TXE 318 /* SCI1�����Хåե�����ץƥ������ */
#define INTNO_SCI1_TXC 319 /* SCI1������λ����� */
#define INTNO_SCI2_RXE 320 /* SCI2�������顼����� */
#define INTNO_SCI2_RXF 321 /* SCI2�����Хåե��ե����� */
#define INTNO_SCI2_TXE 322 /* SCI2�����Хåե�����ץƥ������ */
#define INTNO_SCI2_TXC 323 /* SCI2������λ����� */
#define INTNO_SCI3_RXE 324 /* SCI3�������顼����� */
#define INTNO_SCI3_RXF 325 /* SCI3�����Хåե��ե����� */
#define INTNO_SCI3_TXE 326 /* SCI3�����Хåե�����ץƥ������ */
#define INTNO_SCI3_TXC 327 /* SCI3������λ����� */

/*
 *  �ǥե���Ȥǻ��Ѥ��륷�ꥢ��ݡ��Ȥϥ���ͥ�0
 *  ����������Хå���Ƥ֤���γ�����װ��ϡ�������λ����ߤǤ��뤬��
 *  ����ϡ�������λ����ߤ���٥�ȥꥬ�Ǥ��ꡤ�����Хåե�����ץƥ�
 *  ����ߤ����å��ȥꥬ�Ǥ��뤳�Ȥ˵������롥
 *  ���å��ȥꥬ�ξ�硤�����˼��Ԥ��Ƥ������ߤ���Ĥ���ޤǤδ֤�
 *  �����Хåե������ˤʤäƤ��ޤ��ȡ�����ߤ���Ĥ��Ƥ⡤����ʹߤ�
 *  ����ߤ�ȯ���������ʹߤ��������Ԥ��ʤ��ʤ뤳�Ȥ������ꤦ�롥
 */
#define INHNO_SIO_TX	 INTNO_SCI0_TXC /* ��������ߥϥ�ɥ��ֹ� */
#define INTNO_SIO_TX	 INTNO_SCI0_TXC /* ����������ֹ� */
#define INHNO_SIO_RX	 INTNO_SCI0_RXF /* ��������ߥϥ�ɥ��ֹ� */
#define INTNO_SIO_RX	 INTNO_SCI0_RXF /* ����������ֹ� */
#define INTPRI_SIO		 (-4)			  /* �����ͥ���� */
#define INTATR_SIO		 0U 			  /* �����°�� */

/*
 *  PIO��Ϣ�Υ쥸����
 */
#define PIO_PPR 0xff464030 /* �ݡ��ȥץ�ƥ��ȥ쥸���� */
#define PIO_PPR_UNPROTECT 0xf1 /* �ץ�ƥ��Ȳ���������Ͱʳ���񤭹���ȡ��ץ�ƥ��� */

#define PIO_PA00CR 0xff464040 /* �ݡ���A00����쥸���� */
#define PIO_PA01CR 0xff464042 /* �ݡ���A01����쥸���� */
#define PIO_PA02CR 0xff464044 /* �ݡ���A02����쥸���� */
#define PIO_PA03CR 0xff464046 /* �ݡ���A03����쥸���� */
#define PIO_PA04CR 0xff464048 /* �ݡ���A04����쥸���� */
#define PIO_PA05CR 0xff46404A /* �ݡ���A05����쥸���� */
#define PIO_PA06CR 0xff46404C /* �ݡ���A06����쥸���� */
#define PIO_PA07CR 0xff46404E /* �ݡ���A07����쥸���� */
#define PIO_PA08CR 0xff464050 /* �ݡ���A08����쥸���� */
#define PIO_PA09CR 0xff464052 /* �ݡ���A09����쥸���� */
#define PIO_PA10CR 0xff464054 /* �ݡ���A10����쥸���� */
#define PIO_PA11CR 0xff464056 /* �ݡ���A11����쥸���� */
#define PIO_PA12CR 0xff464058 /* �ݡ���A12����쥸���� */
#define PIO_PA13CR 0xff46405A /* �ݡ���A13����쥸���� */
#define PIO_PA14CR 0xff46405C /* �ݡ���A14����쥸���� */
#define PIO_PA15CR 0xff46405E /* �ݡ���A15����쥸���� */

#define PIO_PB00CR 0xff464080 /* �ݡ���B00����쥸���� */
#define PIO_PB01CR 0xff464082 /* �ݡ���B01����쥸���� */
#define PIO_PB02CR 0xff464084 /* �ݡ���B02����쥸���� */
#define PIO_PB03CR 0xff464086 /* �ݡ���B03����쥸���� */
#define PIO_PB04CR 0xff464088 /* �ݡ���B04����쥸���� */
#define PIO_PB05CR 0xff46408A /* �ݡ���B05����쥸���� */
#define PIO_PB06CR 0xff46408C /* �ݡ���B06����쥸���� */
#define PIO_PB07CR 0xff46408E /* �ݡ���B07����쥸���� */
#define PIO_PB08CR 0xff464090 /* �ݡ���B08����쥸���� */
#define PIO_PB09CR 0xff464092 /* �ݡ���B09����쥸���� */

#define PIO_CR_INE  0x8000 /* ���ϵ��ĥե饰 */
#define PIO_CR_OUTE 0x0010 /* ���ϵ��ĥե饰 */
#define PIO_CR_PSEL_IO  0x0000 /* �ݡ��ȵ�ǽ����PIO or ���յ�ǽ���� */
#define PIO_CR_PSEL_SCI 0x0003 /* �ݡ��ȵ�ǽ����SCI���� */
#define PIO_CR_PSEL_MASK 0x000f /* �ݡ��ȵ�ǽ����Υޥ��� */

#define PIO_PAIN 0xff464062 /* �ݡ���A���ϥ쥸���� */
#define PIO_PBIN 0xff4640A2 /* �ݡ���B���ϥ쥸���� */

#ifndef TOPPERS_MACRO_ONLY

/*
 *  �ӥåȥ졼�Ȥ��顤BR�����ꤹ���ͤ�׻�����ޥ���
 *  f(PBA) / (64 * 2^(2m-1) * br) - 1��m = MD_SCSS
 */
#define CONVERT_BITRATE(br) (uint8_t)(((40000000 * 2) / (64 * 1 * br)) - 1)

extern SIOPCB siopcb_table[TNUM_SCI_PORT];
extern const SIOPINIB siopinib_table[TNUM_SCI_PORT];

/*
 *	SIO�ɥ饤�Фν����
 */
extern void sio_initialize(intptr_t exinf);
extern void sio_hardware_initialize(const SIOPINIB *p_siopinib);

/*
 *	���ꥢ��I/O�ݡ��ȤΥ����ץ�
 */
extern SIOPCB *sio_opn_por(ID siopid, intptr_t exinf);

/*
 *	���ꥢ��I/O�ݡ��ȤΥ�����
 */
extern void sio_cls_por(SIOPCB *p_siopcb);

/*
 *	SIO�γ���ߥϥ�ɥ�
 */
extern void sio_tx_isr(intptr_t exinf);
extern void sio_rx_isr(intptr_t exinf);

/*
 *	���ꥢ��I/O�ݡ��Ȥؤ�ʸ������
 */
extern bool_t sio_snd_chr(SIOPCB *siopcb, char c);

/*
 *	���ꥢ��I/O�ݡ��Ȥ����ʸ������
 */
extern int_t sio_rcv_chr(SIOPCB *siopcb);

/*
 *	���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ε���
 */
extern void sio_ena_cbr(SIOPCB *siopcb, uint_t cbrtn);

/*
 *	���ꥢ��I/O�ݡ��Ȥ���Υ�����Хå��ζػ�
 */
extern void sio_dis_cbr(SIOPCB *siopcb, uint_t cbrtn);

/*
 *	���ꥢ��I/O�ݡ��Ȥ����������ǽ������Хå�
 */
extern void sio_irdy_snd(intptr_t exinf);

/*
 *	���ꥢ��I/O�ݡ��Ȥ���μ������Υ�����Хå�
 */
extern void sio_irdy_rcv(intptr_t exinf);

#endif /* TOPPERS_MACRO_ONLY */
#endif /* TOPPERS_TARGET_SERIAL_H */
