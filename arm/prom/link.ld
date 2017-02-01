/* Script for -z combreloc: combine and sort reloc sections */
OUTPUT_ARCH(arm)
OUTPUT_FORMAT("elf32-littlearm", "elf32-bigarm", "elf32-littlearm")
ENTRY(_start)

/* TODO: INCLUDE(linkcmds.memory) */
MEMORY
{
  rom     : ORIGIN = 0x00000000, LENGTH = 2M
  ram     : ORIGIN = 0x40000000, LENGTH = 4M
}
/* TODO:
REGION_ALIAS("REGION_RODATA", ROM);
REGION_ALIAS("REGION_BSS", ROM);
REGION_ALIAS("REGION_DATA", RAM);
REGION_ALIAS("REGION_TEXT", RAM);
*/

SECTIONS
{
  .interp         : { *(.interp) } >ram
  .note.gnu.build-id : { *(.note.gnu.build-id) } >ram
  .hash           : { *(.hash) } >ram
  .gnu.hash       : { *(.gnu.hash) } >ram
  .dynsym         : { *(.dynsym) } >ram
  .dynstr         : { *(.dynstr) } >ram
  .gnu.version    : { *(.gnu.version) } >ram
  .gnu.version_d  : { *(.gnu.version_d) } >ram
  .gnu.version_r  : { *(.gnu.version_r) } >ram
  .rel.dyn        :
    {
      *(.rel.init)
      *(.rel.text .rel.text.* .rel.gnu.linkonce.t.*)
      *(.rel.fini)
      *(.rel.rodata .rel.rodata.* .rel.gnu.linkonce.r.*)
      *(.rel.data.rel.ro* .rel.gnu.linkonce.d.rel.ro.*)
      *(.rel.data .rel.data.* .rel.gnu.linkonce.d.*)
      *(.rel.tdata .rel.tdata.* .rel.gnu.linkonce.td.*)
      *(.rel.tbss .rel.tbss.* .rel.gnu.linkonce.tb.*)
      *(.rel.ctors)
      *(.rel.dtors)
      *(.rel.got)
      *(.rel.bss .rel.bss.* .rel.gnu.linkonce.b.*)
    } >ram
  .rela.dyn       :
    {
      *(.rela.init)
      *(.rela.text .rela.text.* .rela.gnu.linkonce.t.*)
      *(.rela.fini)
      *(.rela.rodata .rela.rodata.* .rela.gnu.linkonce.r.*)
      *(.rela.data .rela.data.* .rela.gnu.linkonce.d.*)
      *(.rela.tdata .rela.tdata.* .rela.gnu.linkonce.td.*)
      *(.rela.tbss .rela.tbss.* .rela.gnu.linkonce.tb.*)
      *(.rela.ctors)
      *(.rela.dtors)
      *(.rela.got)
      *(.rela.bss .rela.bss.* .rela.gnu.linkonce.b.*)
    } >ram
  .rel.plt        : { *(.rel.plt) } >ram
  .rela.plt       : { *(.rela.plt) } >ram
  .exception_vectors           :
    {
      KEEP (*(.exception_vectors))
    } >ram =0
  .init           :
    {
      KEEP (*(.init))
    } >ram =0
  .plt            : { *(.plt) } >ram
  .text           :
    {
      *(.text .stub .text.* .gnu.linkonce.t.*)
      KEEP (*(.text.*personality*))
      /* .gnu.warning sections are handled specially by elf32.em.  */
      *(.gnu.warning)
      *(.glue_7t) *(.glue_7) *(.vfp11_veneer)
    } >ram =0
  .fini           :
    {
      KEEP (*(.fini))
    } >ram =0
  PROVIDE (__etext = .);
  PROVIDE (_etext = .);
  PROVIDE (etext = .);
  .rodata         : { *(.rodata .rodata.* .gnu.linkonce.r.*) } >ram
  .rodata1        : { *(.rodata1) } >ram
  .ARM.extab      : { *(.ARM.extab* .gnu.linkonce.armextab.*) } >ram
   __exidx_start = .;
  .ARM.exidx      : { *(.ARM.exidx* .gnu.linkonce.armexidx.*) } >ram
   __exidx_end = .;
  .eh_frame_hdr   : { *(.eh_frame_hdr) } >ram
  .eh_frame       : ONLY_IF_RO { KEEP (*(.eh_frame)) } >ram
  .gcc_except_table   : ONLY_IF_RO { *(.gcc_except_table .gcc_except_table.*) } >ram
  /* Adjust the address for the data segment.  We want to adjust up to
     the same address within the page on the next page up.  */
  . = ALIGN(CONSTANT (MAXPAGESIZE)) + (. & (CONSTANT (MAXPAGESIZE) - 1));
  /* Exception handling  */
  .eh_frame       : ONLY_IF_RW { KEEP (*(.eh_frame)) } >ram
  .gcc_except_table   : ONLY_IF_RW { *(.gcc_except_table .gcc_except_table.*) } >ram
  /* Thread Local Storage sections  */
  .tdata          : { *(.tdata .tdata.* .gnu.linkonce.td.*) } >ram
  .tbss           : { *(.tbss .tbss.* .gnu.linkonce.tb.*) *(.tcommon) } >ram
  .preinit_array     :
    {
      PROVIDE_HIDDEN (__preinit_array_start = .);
      KEEP (*(.preinit_array))
      PROVIDE_HIDDEN (__preinit_array_end = .);
    } >ram
  .init_array     :
    {
      PROVIDE_HIDDEN (__init_array_start = .);
      KEEP (*(SORT(.init_array.*)))
      KEEP (*(.init_array))
      PROVIDE_HIDDEN (__init_array_end = .);
    } >ram
  .fini_array     :
    {
      PROVIDE_HIDDEN (__fini_array_start = .);
      KEEP (*(.fini_array))
      KEEP (*(SORT(.fini_array.*)))
      PROVIDE_HIDDEN (__fini_array_end = .);
    } >ram
  .ctors          :
    {
      /* gcc uses crtbegin.o to find the start of
        the constructors, so we make sure it is
        first.  Because this is a wildcard, it
        doesn't matter if the user does not
        actually link against crtbegin.o; the
        linker won't look for a file to match a
        wildcard.  The wildcard also means that it
        doesn't matter which directory crtbegin.o
        is in.  */
      KEEP (*crtbegin.o(.ctors))
      KEEP (*crtbegin?.o(.ctors))
      /* We don't want to include the .ctor section from
        the crtend.o file until after the sorted ctors.
        The .ctor section from the crtend file contains the
        end of ctors marker and it must be last */
      KEEP (*(EXCLUDE_FILE (*crtend.o *crtend?.o ) .ctors))
      KEEP (*(SORT(.ctors.*)))
      KEEP (*(.ctors))
    } >ram
  .dtors          :
    {
      KEEP (*crtbegin.o(.dtors))
      KEEP (*crtbegin?.o(.dtors))
      KEEP (*(EXCLUDE_FILE (*crtend.o *crtend?.o ) .dtors))
      KEEP (*(SORT(.dtors.*)))
      KEEP (*(.dtors))
    } >ram
  .jcr            : { KEEP (*(.jcr)) } >ram
  .data.rel.ro : { *(.data.rel.ro.local* .gnu.linkonce.d.rel.ro.local.*) *(.data.rel.ro* .gnu.linkonce.d.rel.ro.*) } >ram
  .dynamic        : { *(.dynamic) } >ram
  .got            : { *(.got.plt) *(.got) } >ram
  .data           :
    {
      __data_start = . ;
      *(.data .data.* .gnu.linkonce.d.*)
      KEEP (*(.gnu.linkonce.d.*personality*))
      SORT(CONSTRUCTORS)
    } >ram
  .data1          : { *(.data1) } >ram
  _edata = .; PROVIDE (edata = .);
  __bss_start = .;
  __bss_start__ = .;
  .bss            :
    {
    *(.dynbss)
    *(.bss .bss.* .gnu.linkonce.b.*)
    *(COMMON)
    /* Align here to ensure that the .bss section occupies space up to
        _end.  Align after .bss to ensure correct alignment even if the
        .bss section disappears because there are no input sections.
        FIXME: Why do we need it? When there is no .bss section, we don't
        pad the .data section.  */
    . = ALIGN(. != 0 ? 32 / 8 : 1);
    } >ram
  _bss_end__ = . ; __bss_end__ = . ;
  . = ALIGN(32 / 8);
  . = ALIGN(32 / 8);
  __end__ = . ;
  _end = .; PROVIDE (end = .);
  /* Stabs debugging sections.  */
  .stab          0 : { *(.stab) } >ram
  .stabstr       0 : { *(.stabstr) } >ram
  .stab.excl     0 : { *(.stab.excl) } >ram
  .stab.exclstr  0 : { *(.stab.exclstr) } >ram
  .stab.index    0 : { *(.stab.index) } >ram
  .stab.indexstr 0 : { *(.stab.indexstr) } >ram
  .comment       0 : { *(.comment) } >ram
  /* DWARF debug sections.
     Symbols in the DWARF debugging sections are relative to the beginning
     of the section so we begin them at 0.  */
  /* DWARF 1 */
  .debug          0 : { *(.debug) } >ram
  .line           0 : { *(.line) } >ram
  /* GNU DWARF 1 extensions */
  .debug_srcinfo  0 : { *(.debug_srcinfo) } >ram
  .debug_sfnames  0 : { *(.debug_sfnames) } >ram
  /* DWARF 1.1 and DWARF 2 */
  .debug_aranges  0 : { *(.debug_aranges) } >ram
  .debug_pubnames 0 : { *(.debug_pubnames) } >ram
  /* DWARF 2 */
  .debug_info     0 : { *(.debug_info .gnu.linkonce.wi.*) } >ram
  .debug_abbrev   0 : { *(.debug_abbrev) } >ram
  .debug_line     0 : { *(.debug_line) } >ram
  .debug_frame    0 : { *(.debug_frame) } >ram
  .debug_str      0 : { *(.debug_str) } >ram
  .debug_loc      0 : { *(.debug_loc) } >ram
  .debug_macinfo  0 : { *(.debug_macinfo) } >ram
  /* SGI/MIPS DWARF 2 extensions */
  .debug_weaknames 0 : { *(.debug_weaknames) } >ram
  .debug_funcnames 0 : { *(.debug_funcnames) } >ram
  .debug_typenames 0 : { *(.debug_typenames) } >ram
  .debug_varnames  0 : { *(.debug_varnames) } >ram
  /* DWARF 3 */
  .debug_pubtypes 0 : { *(.debug_pubtypes) } >ram
  .debug_ranges   0 : { *(.debug_ranges) } >ram
  .stack   0x60000000 :
    {
      _stack = .;
      __stack = .;
      *(.stack)
    } >ram
  .ARM.attributes 0 : { KEEP (*(.ARM.attributes)) KEEP (*(.gnu.attributes)) } >ram
  .note.gnu.arm.ident 0 : { KEEP (*(.note.gnu.arm.ident)) } >ram
  /DISCARD/       : { *(.note.GNU-stack) *(.gnu_debuglink) } >ram
}
