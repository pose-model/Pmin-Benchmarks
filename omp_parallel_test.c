/*
 * All threads sit on a nop loop
 */
void main() {
    #pragma omp parallel
    {
        __asm__ volatile ("nop: jmp nop");
    }
}
