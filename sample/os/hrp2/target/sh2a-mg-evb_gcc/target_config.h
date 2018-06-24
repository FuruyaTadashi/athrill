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
 *	�������åȰ�¸�⥸�塼���SH2A-MG_EVB�ѡ�
 *
 *	�����ͥ�Υ������åȰ�¸���Υ��󥯥롼�ɥե����롥kernel_impl.h�Υ���
 *	���åȰ�¸���ΰ����դ��Ȥʤ롥
 */

#ifndef TOPPERS_TARGET_CONFIG_H
#define TOPPERS_TARGET_CONFIG_H

#include <sil.h>

/*
 *	�������åȥ����ƥ�Υϡ��ɥ������񸻤����
 */
#include "sh72aw.h"

#include "target_mpu.h"

/*
 *	�ȥ졼�����˴ؤ�������
 */
#ifdef TOPPERS_ENABLE_TRACE
#include "logtrace/trace_config.h"

/*
 *	���Ϥ�������̤����
 *	��ɬ�פ˱�����asp/arch/logtrace/trace_dump.c��trace_print()��
 *	���б���������̤��ɵ����롣
 */
#define LOG_INH_ENTER			/*	 17(0x11)  */
#define LOG_INH_LEAVE			/*	145(0x91)  */
#define LOG_EXC_ENTER			/*	 22(0x16)  */
#define LOG_EXC_LEAVE			/*	150(0x96)  */

#endif /* TOPPERS_ENABLE_TRACE */

/*
 *  cfg�Υѥ�2��ɬ�פȤʤ�ޥ���
 */
#define TARGET_INTATR (TA_POSEDGE | TA_NEGEDGE | TA_LOWLEVEL)
#define CHECK_STKSZ_ALIGN 4

/*
 *  cfg�Υѥ�3��ɬ�פȤʤ�ޥ���
 */
#define CHECK_FUNC_ALIGN  2
#define CHECK_FUNC_NONNULL  1
#define CHECK_STACK_ALIGN  4
#define CHECK_STACK_NONNULL 1
#define CHECK_MPF_ALIGN 4
#define CHECK_MPF_NONNULL 1

/*
 *	�������åȰ�¸��ʸ�����Ϥ˻��Ѥ���ݡ��Ȥ����
 */
#define TARGET_PUTC_PORTID 1

/*
 *	HRP�����ͥ�ư����Υ���ޥåפȴ�Ϣ�������
 */

/*
 *  RAM��0xFFF8 0000 - 0xFFF8 7FFF(32KB) <- �ꥻ�åȸ�
 *       0xFFF8 0000 - 0xFFF9 7FFF(96KB)
 */

/*
 *	�ǥե���Ȥ��󥿥�������ƥ������ѤΥ����å��ΰ�����
 */
/*  �����å�������  */
#define DEFAULT_ISTKSZ 0x800U /* 2048�Х��� */

/*	�����å��ΰ���� */
#define DEFAULT_ISTK_BOTTOM 0xfff88000 /* RAM���� */

/*	�����å��ΰ����Ƭ���ϡʥ����å��ΰ����ǤϤʤ��Τǡ���ա� */
#define DEFAULT_ISTK	  (void *)(DEFAULT_ISTK_BOTTOM - DEFAULT_ISTKSZ)

#ifndef TOPPERS_MACRO_ONLY

#define DEFAULT_SSTKSZ 1280 

/*
 *	���������������ƥ����ȥ֥�å�
 */

#define USE_TSKINICTXB	/*  TSKINICTXB����Ѥ���  */

typedef struct task_initialization_context_block {
	SIZE	sstksz;			/* �����å��ΰ�Υ������ʴݤ᤿�͡� */
	void	*sstk_bottom;	/* �����å��ݥ��󥿤ν���͡ʥ����å�����ν���͡� */
	SIZE	stksz;			/* �����å��ΰ�Υ������ʴݤ᤿�͡� */
	void	*stk_bottom;	/* �����å��ݥ��󥿤ν���͡ʥ����å�����ν���͡� */
    void    *sustk; /* �桼�������å�����Ƭ���� */
    void    *eustk; /* �桼�������å��ν�λ���� */
} TSKINICTXB;

/*
 *  �ݸ�ɥᥤ����������ƥ����ȥ֥�å�
 */

#define USE_DOMINICTXB	/*  TSKINICTXB����Ѥ���  */

typedef struct {
    void *stext;
    void *etext;
    void *srodata;
    void *erodata;
    void *sdata;
    void *edata;
    void *ssrpw;
    void *esrpw;
    uint32_t *valid_map;
} DOMINICTXB;

/*
 *  �桼�����������ø��⡼�ɼ¹��椫��
 *  priv_mode�ϡ������ӥ������롢����ӡ���ĥ�����ӥ��������
 *  �����������true�˥��åȤ����
 */
#define t_sense_priv(p_tcb) ((p_tcb)->tskctxb.priv_mode == true)
#define i_sense_priv(p_tcb) ((p_tcb)->tskctxb.priv_mode == true)
#define t_sense_priv_runtsk() ((p_runtsk)->tskctxb.priv_mode == true)
#define i_sense_priv_runtsk() ((p_runtsk)->tskctxb.priv_mode == true)

/*
 *  �桼���������Υ������㳰�����ƤӽФ����˻��Ѥ��륹���å���������­��ʤ�����
 *  i_check_tex_runtsk�ϡ��󥿥�������ƥ����Ȥ���ƤФ��Τǡ�
 *  �桼�������å���TCB����¸����Ƥ���Ϥ��Ǥ���
 */
extern bool_t i_check_tex_runtsk();

/*
 *	�������åȥ����ƥ��¸�ν����
 */
extern void target_initialize(void);
extern void target_fput_initialize(void);
extern void target_fput_log(char c);

/*
 *	�������åȥ����ƥ�ν�λ
 *
 *	�����ƥ��λ������˻Ȥ���
 */
extern void target_exit(void) NoReturn;

/*
 * CPU�㳰�ֹ�˴ؤ������
 */
#define TMIN_EXCNO		UINT_C(4)		/*	GENERAL_ILLEGAL_INSTRUCTION_VECTOR	*/
#define TMAX_EXCNO		UINT_C(63)		/*	TRAPA_INST_VECTOR  */
#define TNUM_EXC		(TMAX_EXCNO - TMIN_EXCNO + 1U)

/*
 *	�㳰�٥���
 */
#define POWER_ON_RESET_VECTOR				0
#define MANUAL_RESET_VECTOR					2
#define GENERAL_ILLEGAL_INSTRUCTION_VECTOR	4
#define RAM_ERROR_VECTOR					5
#define SLOT_ILLEGAL_INSTRUCTION_VECTOR		6
#define CPU_ADDRESS_ERROR_VECTOR			9
#define DMA_ADDRESS_ERROR_VECTOR			10
#define FPU_VECTOR							13
#define BANK_OVER_FLOW_VECTOR				15
#define BANK_UNDER_FLOW_VECTOR				16
#define DIVIDE_BY_ZERO_VECTOR				17


/*
 * ����ߥϥ�ɥ��ֹ�˴ؤ������
 */
#define TMIN_INHNO		UINT_C(64)
#define TMAX_INHNO		UINT_C(493)
#define TNUM_INH		(TMAX_INHNO - TMIN_INHNO + 1U)

/*
 * ������ֹ�˴ؤ������
 */
#define TMIN_INTNO		UINT_C(64)
#define TMAX_INTNO		UINT_C(493)
#define TNUM_INT		(TMAX_INTNO - TMIN_INTNO + 1U)

/*	IRQ  */
#define TMIN_INTNO_IRQ 	64U
#define TMAX_INTNO_IRQ	71U

/*
 *  ����ߴ�Ϣ�Υ쥸����
 */
#define INTC_BCR 0xfffd940e /* �Х�����쥸���� */
#define INTPRI2BCR(intpri) (0x0001 << (uint16_t)intpri) /* �����ͥ���٤���BCR�����ꤹ���ͤ�����ޥ��� */
#define INTC_BNR 0xfffd9410 /* �Х��ֹ�쥸���� */
#define INTC_BNR_BE_DISABLE_ALL  0x0000 /* ���٤Ƥγ���ߤǥХ󥯤�ػ� */
#define INTC_BNR_BE_DISABLE_PART 0x4000 /* �ᥤ�󥯥�å�ȯ����ߡ��桼���֥졼���Τߵ��� */
#define INTC_BNR_BE_BCR 0xC000 /* BCR������˽��� */

/*
 *  ���յ�ǽ������ֹ�Υ١���
 *  peripheral block
 */
#define INTC_PB_INTNO_BASE 102

/*
 *  ���յ�ǽ������׵�쥸�����Υ١������ɥ쥹
 *  1byte����������
 */
#define INTC_PB_IR_BASE 0xfffd9800

/*
 *  ���յ�ǽ���������쥸�����Υ١������ɥ쥹
 *  2byte����������
 */
#define INTC_PB_ICR_BASE 0xfffd999a
#define INTC_PB_ICR_INTEN 0x8000    /* ����ߵ��ġʥӥåȤ�0�ʤ�жػߡ� */
#define INTC_PB_ICR_IPR_MASK 0x000f /* �����ͥ���٤Υޥ��� */

/*	CFG_INT�ǳ����ͥ���٤����ꤵ��Ƥ��ʤ����Ȥ򼨤��ӥå�  */
#ifndef NOT_CFG_INT_BIT
#define NOT_CFG_INT_BIT		0x80U
#endif /* NOT_CFG_INT_BIT */

extern const uint8_t int_iipm_tbl[TNUM_INT];


/*
 *  ������׵�Υ����å�
 */
Inline bool_t 
x_probe_int(INTNO intno)
{
    return ((sil_reb_mem((void *)(INTC_PB_IR_BASE + (intno - INTC_PB_INTNO_BASE))) & 0x01) == 0x01);
}

#define t_probe_int(intno) x_probe_int(intno)
#define i_probe_int(intno) x_probe_int(intno)

/*
 *  ������׵�Υ��ꥢ
 */
Inline void
x_clear_int(INTNO intno)
{
    sil_wrb_mem((void *)(INTC_PB_IR_BASE + (intno - INTC_PB_INTNO_BASE)), 0x00);
}

#define t_clear_int(intno) x_clear_int(intno)
#define i_clear_int(intno) x_clear_int(intno)

/*
 *  ����߶ػ�
 */
Inline bool_t
x_disable_int(INTNO intno)
{
    uint8_t iipm = int_iipm_tbl[intno - TMIN_INTNO];

    if((iipm & NOT_CFG_INT_BIT) != 0){
        return false;
    }

    sil_wrh_mem((void *)(INTC_PB_ICR_BASE + (intno - INTC_PB_INTNO_BASE) * 2), 
            (sil_reh_mem((void *)(INTC_PB_ICR_BASE + (intno - INTC_PB_INTNO_BASE) * 2)) & ~INTC_PB_ICR_INTEN));

    return true;
}

#define t_disable_int(intno) x_disable_int(intno)
#define i_disable_int(intno) x_disable_int(intno)

/*
 *  ����ߵ���
 */
Inline bool_t
x_enable_int(INTNO intno)
{
    uint32_t iipm = int_iipm_tbl[intno - TMIN_INTNO];

    if((iipm & NOT_CFG_INT_BIT) != 0){
        return false;
    }

    sil_wrh_mem((void *)(INTC_PB_ICR_BASE + (intno - INTC_PB_INTNO_BASE) * 2), 
            (sil_reh_mem((void *)(INTC_PB_ICR_BASE + (intno - INTC_PB_INTNO_BASE) * 2)) | INTC_PB_ICR_INTEN));

    return true;
}

#define t_enable_int(intno) x_enable_int(intno)
#define i_enable_int(intno) x_enable_int(intno)


#endif /* TOPPERS_MACRO_ONLY */

#define USRTEX_STKSZ (4*2)

/*
 *	���������Ԥ��Τ��������������SIL�Υ������åȰ�¸����
 */
#define SIL_DLY_TIM1    30 /* 160MHz�ǡ���5̿�� */
#define SIL_DLY_TIM2    24 /* 160MHz�ǡ���4̿�� */

/*
 *  ����ߵ��Ĥ�ͭ���ˤʤ�ޤǤλ����Ԥ��򤹤뤿���nop̿��
 *  
 *  ��SH7211�ϰ���Ū�ʥ���å������¢���Ƥ��ʤ�����ˡ�
 *  ����¢�ե�å���ROM���Ф��ƤΤ�ͭ����ROM����å����
 *  ����¢���Ƥ��롣����ROM����å���Ͼ��ON�ǡ�OFF�ˤϤǤ��ʤ���
 *  �����Τ��ᡢENABLE_CACHE�ޥ���ǤϤʤ���ROM_BOOT�ޥ����
 *  ���Ѥ��ơ��ٱ��ɬ�פ�̿�����Ƚ�̤��Ƥ��롣
 */
#ifdef ROM_BOOT		/*  ROM����å���αƶ����������  */
	/*
	 *  ROM����å���θ��̤��θ
	 *  ����CPU����INTC����ã�����ޤǤ��ٱ�
	 *  �����ʥ����ѥ������3I��cycʬ��6̿��� 
	 */

	/*  �ǥ����ѥå�����  */
#define LDC_NOP_DISPATCHER		nop; nop; nop; nop; nop; nop

	/*  set_sr�ѡ����Υ������åȤǤ�ɬ�פʤ�  */
// #define LDC_NOP_SET_SR			"nop; nop"

	/*  TOPPERS_set_iipm�Ѥ�target_sil.h�˵��Ҥ��롣  */

#endif	/*  ROM_BOOT  */

/*
 *	�����μ���
 */
#define SH2A

/*
 *	���ѤǤ���̿�᥻�å�
 *	��SH1��̿��ˤĤ��Ƥϡ����٤ƤΥ����ǥ��ݡ��Ȥ����Τǡ�
 *	��������ʤ���
 */
#define TOPPERS_SUPPORT_SH2_INSTRUCTION
#define TOPPERS_SUPPORT_SH2E_INSTRUCTION
#define TOPPERS_SUPPORT_SH2A_INSTRUCTION

#ifndef TOPPERS_TARGET_SUPPORT_OVRHDR
#define TOPPERS_TARGET_SUPPORT_OVRHDR
#endif /* TOPPERS_TARGET_SUPPORT_OVRHDR */

/*
 *	IRQ����ߤ��ɤ�����Ƚ�ꤹ�뤿��Υޥ���
 *	��prc_config.h��������٤����������Υե��������x_config_intatr()
 *	���ǻ��Ѥ��뤿�ᡢ�����˵��Ҥ��Ƥ��롣
 */
#define INTNO_IS_IRQ(intno) 								\
		((TMIN_INTNO_IRQ <= (intno)) && ((intno) <= TMAX_INTNO_IRQ))

/*
 *	������ֹ椫��IRQ�ֹ�ؤ��Ѵ�
 */
#define INTNO_TO_IRQNO(intno) (((intno) - TMIN_INTNO_IRQ))

#define TEXCNO_EMULATE_TEXRTN 20
#define TEXCNO_EMULATE_RET_TEX 21

#ifndef TOPPERS_MACRO_ONLY

#include <sil.h>

/*
 * IRC�ν����
 */
Inline void
irc_initialize(void)
{
    /*
     *  ���٤Ƥγ���ߤǥХ󥯤�ػ�
     */
    sil_wrh_mem((void *)INTC_BNR, INTC_BNR_BE_DISABLE_ALL);
}

/*
 *	����ߥϥ�ɥ�������ɬ�פ�IRC���
 *
 *	IRQ����ߤǤ��ĥ��å��ȥꥬ�ξ��ϳ�����׵�򥯥ꥢ���롥
 *	���å��ȥꥬ����٥�ȥꥬ����Ƚ�̤���ȥ����С��إåɤ��礭���Τǡ�
 *	��˥��ꥢ���롥
 *	�ʥ�٥�ȥꥬ�ǥ��ꥢ�����򤷤ƤⳲ�Ϥʤ�����
 *
 *	IRQRR�쥸��������١����ߡ��꡼�ɤ��ơ� �����ӥåȤ�0��񤭹��ࡣ
 *	���δ֡�������ߥ�å����֤ˤ��Ƥ���Τϡ��ʲ��Τ褦�ʥ��������ɤ�
 *	���ᡣ
 *
 *	3����γ���ߤ�ͤ��롣
 *	�����ͥ���٤ϡ�l > m > n�ν�Ȥ��롣
 *	�ʳ����l��ͥ���٤��⤤����
 *	
 *	1.	m�γ���ߤ�ȯ��(m�ӥåȤ����å�)
 *	2.	m�γ���ߥϥ�ɥ餬�¹�(n�ϳ���߶ػ�)
 *	3.	IRQRR�꡼��(l = 0, m = 1, n = 0)
 *	4.	l�γ���ߤ�ȯ��(l�ӥåȤ����å�)
 *	5.	l�γ���ߥϥ�ɥ餬�¹�(n�ϳ���߶ػ�)
 *	6.	n�γ���ߤ�ȯ������α��(n�ӥåȤ����å�)
 *	7.	IRQRR�꡼��(l = 1, m = 1, n = 1)
 *	8.	IRQRR�饤��(l = 0, m = 1, n = 1)
 *	9.	l�γ���ߥϥ�ɥ齪λ
 *	10. m�γ���ߥϥ�ɥ�Ƴ�
 *	11. IRQQ�饤��(l = 0, m = 0, n = 0)
 *	
 *	11���ʳ��� n �����ꥢ������ǽ�������롥
 */
Inline void
i_begin_int(INTNO intno)
{
}

extern void target_mpu_initialize(void);
extern void target_mpu_handler(void);

#endif /* TOPPERS_MACRO_ONLY */

#include "sh12a_gcc/prc_config.h"

#endif	/* TOPPERS_TARGET_CONFIG_H */
