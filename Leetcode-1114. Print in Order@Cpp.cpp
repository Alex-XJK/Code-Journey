#include <semaphore.h>

class Foo {
private:
    sem_t* sem1 = new sem_t;
    sem_t* sem2 = new sem_t;
public:
    Foo() {
        sem_init(sem1, 0, 0);
        sem_init(sem2, 0, 0);
    }

    void first(function<void()> printFirst) {
        // Wait signal
        // NONE
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        
        // Send signal
        sem_post(sem1);
    }

    void second(function<void()> printSecond) {
        // Wait signal
        sem_wait(sem1);
        
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        
        // Send signal
        sem_post(sem2);
    }

    void third(function<void()> printThird) {
        // Wait signal
        sem_wait(sem2);
        
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        
        // Send signal
        // NONE
    }
};