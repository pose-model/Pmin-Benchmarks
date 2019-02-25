/* All ranks do some random parallel work
 * Then a nop loop outside of a parallel region
 */
void main() {
    #pragma omp parallel
    {
        volatile int i;
        i = 1;
    }

    __asm__ volatile ("nop: jmp nop");

    #pragma omp parallel
    {
        volatile int i;
        i = 1;
    }
}
