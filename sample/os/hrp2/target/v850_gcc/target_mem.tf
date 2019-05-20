$ ======================================================================
$
$   TOPPERS/HRP Kernel
$       Toyohashi Open Platform for Embedded Real-Time Systems/
$       High Reliable system Profile Kernel
$
$   Copyright (C) 2011-2012 by Embedded and Real-Time Systems Laboratory
$               Graduate School of Information Science, Nagoya Univ., JAPAN
$  
$   �嵭����Ԥϡ��ʲ���(1)��(4)�ξ������������˸¤ꡤ�ܥ��եȥ���
$   �����ܥ��եȥ���������Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ������
$   �ѡ������ۡʰʲ������ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
$   (1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭������
$       ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ���
$       ����������˴ޤޤ�Ƥ��뤳�ȡ�
$   (2) �ܥ��եȥ������򡤥饤�֥������ʤɡ�¾�Υ��եȥ�������ȯ�˻�
$       �ѤǤ�����Ǻ����ۤ�����ˤϡ������ۤ�ȼ���ɥ�����ȡ�����
$       �ԥޥ˥奢��ʤɡˤˡ��嵭�����ɽ�����������Ѿ�浪��Ӳ���
$       ��̵�ݾڵ����Ǻܤ��뤳�ȡ�
$   (3) �ܥ��եȥ������򡤵�����Ȥ߹���ʤɡ�¾�Υ��եȥ�������ȯ�˻�
$       �ѤǤ��ʤ����Ǻ����ۤ�����ˤϡ����Τ����줫�ξ�����������
$       �ȡ�
$     (a) �����ۤ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭����
$         �ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
$     (b) �����ۤη��֤��̤�������ˡ�ˤ�äơ�TOPPERS�ץ������Ȥ�
$         ��𤹤뤳�ȡ�
$   (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
$       ������⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ����դ��뤳�ȡ�
$       �ޤ����ܥ��եȥ������Υ桼���ޤ��ϥ���ɥ桼������Τ����ʤ���
$       ͳ�˴�Ť����ᤫ��⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ�
$       ���դ��뤳�ȡ�
$  
$   �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ�
$   ���TOPPERS�ץ������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����λ�����Ū
$   ���Ф���Ŭ������ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ���
$   �������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤��
$   ����Ǥ�����ʤ���
$
$ =====================================================================

$FUNCTION GET_SSTK_TSKINICTXB$
    $bottom = PEEK(ARGV[1] + offsetof_TINIB_TSKINICTXB_sstk_bottom, sizeof_void_ptr)$
    $size = PEEK(ARGV[1] + offsetof_TINIB_TSKINICTXB_sstksz, sizeof_SIZE)$
    $RESULT = (bottom - size)$
$END$

$FUNCTION GET_USTK_TSKINICTXB$
    $bottom = PEEK(ARGV[1] + offsetof_TINIB_TSKINICTXB_stk_bottom, sizeof_void_ptr)$
    $size = PEEK(ARGV[1] + offsetof_TINIB_TSKINICTXB_stksz, sizeof_SIZE)$
    $RESULT = (bottom - size)$
$END$

$INCLUDE "sh12a_gcc/prc_mem.tf"$

$FILE "kernel_mem.c"$

$ 
$  �桼�������å���ɬ��ͭ���Ǥ���
$  �٥����ơ��֥롤�٥���������ȥꡤMPUͭ���쥸������ɬ��ͭ���Ǥ���
$  ���������ɤ�0xaaaa0000
$ 
$VALID_MAP_INIT = (0x00000000 | (1 << 4) | (1 << 9) | (1 << 10) | (1 << 11) | 0xaaaa0000)$

$IF LENGTH(DOM.ID_LIST)$
    $shared_meminib = SYMBOL("shared_meminib_table")$
    $FOREACH id_bit RANGE(5,8)$
$   �ΰ�γ��ϥ��ɥ쥹���ɤ߹��� 
        $start_address = PEEK(shared_meminib, 4)$
        $shared_meminib = shared_meminib + 4$
$   �ΰ�ν�λ���ɥ쥹���ɤ߹��� 
        $end_address = PEEK(shared_meminib, 4) + 4$
        $shared_meminib = shared_meminib + 4$

        $IF start_address != end_address$
            $VALID_MAP_INIT = VALID_MAP_INIT | (1 << id_bit)$ 
        $END$
    $END$

    $dominib = SYMBOL("_kernel_dominib_table")$
	const uint32_t dom_valid_map_table[TNUM_DOMID] = {$NL$
	$JOINEACH domid DOM.ID_LIST ",\n"$
        $WARNING$
            $FORMAT("domid = %s\n",domid)$
        $END$
$   �����������ĥѥ�����ϥѥ�����
        $dominib = dominib + sizeof_ACPTN$
        $valid_map = VALID_MAP_INIT$
        $FOREACH id_bit RANGE(0,3)$
$   �ΰ�γ��ϥ��ɥ쥹���ɤ߹��� 
            $start_address = PEEK(dominib, 4)$
            $dominib = dominib + 4$
$   �ΰ�ν�λ���ɥ쥹���ɤ߹��� 
            $end_address = PEEK(dominib, 4) + 4$
            $dominib = dominib + 4$

            $IF start_address != end_address$
               $valid_map = valid_map | (1 << id_bit)$ 
            $END$
        $END$
        $TAB$$FORMAT("0x%08x", +valid_map)$
$   ͭ���ӥåȤΥ��ɥ쥹�ϥѥ�����
        $dominib = dominib + 4$
	$END$,$NL$
	};$NL$
	$NL$
$ELSE$
	const DOMINIB dom_valid_map_table[0];$NL$
$END$$NL$


