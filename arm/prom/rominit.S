#ifdef __ELF__
#define TYPE(x) .type x,function
#else
#define TYPE(x)
#endif

.section        ".exception_vectors", "ax"
.align 2
.global _exception_vectors
TYPE(_exception_vectors)

_exception_vectors:
    mov pc, #1073741824 // 0x40000000
    nop      // vector for undefined instructions
    nop      // vector for software interrupts
    nop      // vector for prefectch abort
    nop      // vector for data abort
    nop                // blank word
    nop      // vector for IRQ (normal interrupts)
    nop      // vector for FIQ (fast interrupts)
    nop                // lets leave a blank word before the start of the real code
    .end _exception_vectors
