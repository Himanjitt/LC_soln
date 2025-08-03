class FooBar {
private:
    int n;
    bool isFooPrinted;
    mutex mtx;
    condition_variable cv;

public:
    FooBar(int n) {
        this->n = n;
        isFooPrinted = false;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this]{return !isFooPrinted;});
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            isFooPrinted = true;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this]{return isFooPrinted;});
        	printBar();
            isFooPrinted = false;
            cv.notify_all();
        	
        }
    }
};