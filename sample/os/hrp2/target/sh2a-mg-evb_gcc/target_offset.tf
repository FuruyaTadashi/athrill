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

$  ���åװ�¸���Υƥ�ץ졼�ȥե�����Υ��󥯥롼��
$INCLUDE "sh12a_gcc/prc_offset.tf"$

$DEFINE("TINIB_sstksz", offsetof_TINIB_TSKINICTXB_sstksz)$
$DEFINE("TINIB_sstk_bottom", offsetof_TINIB_TSKINICTXB_sstk_bottom)$
$DEFINE("TINIB_p_dominib", offsetof_TINIB_p_dominib)$
$DEFINE("TINIB_sustk", offsetof_TINIB_sustk)$
$DEFINE("TINIB_eustk", offsetof_TINIB_eustk)$
$DEFINE("TINIB_texrtn", offsetof_TINIB_texrtn)$
$DEFINE("TCB_svclevel", offsetof_TCB_svclevel)$
$DEFINE_BIT("TCB_waifbd", sizeof_TCB, "B")$
$DEFINE("TCB_priv_mode", offsetof_TCB_priv_mode)$

$DEFINE("DOMINIB_domptn", offsetof_DOMINIB_domptn)$
$DEFINE("DOMINIB_stext", offsetof_DOMINIB_stext)$
$DEFINE("DOMINIB_etext", offsetof_DOMINIB_etext)$
$DEFINE("DOMINIB_srodata", offsetof_DOMINIB_srodata)$
$DEFINE("DOMINIB_erodata", offsetof_DOMINIB_erodata)$
$DEFINE("DOMINIB_sdata", offsetof_DOMINIB_sdata)$
$DEFINE("DOMINIB_edata", offsetof_DOMINIB_edata)$
$DEFINE("DOMINIB_ssrpw", offsetof_DOMINIB_ssrpw)$
$DEFINE("DOMINIB_esrpw", offsetof_DOMINIB_esrpw)$
$DEFINE("DOMINIB_valid_map", offsetof_DOMINIB_valid_map)$

