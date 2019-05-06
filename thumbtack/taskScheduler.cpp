class Task {
    using Clock = std::chrono::system_clock;

    public:
    Task(string name, int timeOut, std::function<void()> &&f) : 
        name(name),timeOut(std::chrono::seconds(timeOut)), f(std::move(f)) {
        
    }
    string name;
    Clock::duration timeOut;
    std::function<void()> f;
};

class InterruptableSleep {

        using Clock = std::chrono::system_clock;

        // InterruptableSleep offers a sleep that can be interrupted by any thread.
        // It can be interrupted multiple times
        // and be interrupted before any sleep is called (the sleep will immediately complete)
        // Has same interface as condition_variables and futures, except with sleep instead of wait.
        // For a given object, sleep can be called on multiple threads safely, but is not recommended as behaviour is undefined.

    public:
        InterruptableSleep() : interrupted(false) {
        }

        InterruptableSleep(const InterruptableSleep &) = delete;

        InterruptableSleep(InterruptableSleep &&) noexcept = delete;

        ~InterruptableSleep() noexcept = default;

        InterruptableSleep &operator=(const InterruptableSleep &) noexcept = delete;

        InterruptableSleep &operator=(InterruptableSleep &&) noexcept = delete;

        void sleep_for(Clock::duration duration) {
          std::unique_lock<std::mutex> ul(m);
          cv.wait_for(ul, duration, [this] { return interrupted; });
          interrupted = false;
        }

        void sleep_until(Clock::time_point time) {
          std::unique_lock<std::mutex> ul(m);
          cv.wait_until(ul, time, [this] { return interrupted; });
          interrupted = false;
        }

        void sleep() {
          std::unique_lock<std::mutex> ul(m);
          cv.wait(ul, [this] { return interrupted; });
          interrupted = false;
        }

        void interrupt() {
          std::lock_guard<std::mutex> lg(m);
          interrupted = true;
          cv.notify_one();
        }

    private:
        bool interrupted;
        std::mutex m;
        std::condition_variable cv;
    };

class TaskScheduler {
    using Clock = std::chrono::system_clock;
public:
    TaskScheduler(){
        checkThread = shared_ptr<thread>(new thread(&TaskScheduler::check, this));
    }

    ~TaskScheduler() {
        done = true;
    }
    void check(){
        while(!done){
            if(tasks.empty()){
                sleeper.sleep();
            }else{
                auto time_to_first_task = (*tasks.begin()).first;
                sleeper.sleep_until(time_to_first_task);
                // std::time_t now_c = std::chrono::system_clock::to_time_t(time_to_first_task);
                // cout << std::ctime(&now_c) << endl;
            }
            manageTask();
        }
    }
    void stop() {
        checkThread->join();
    }
    void schedule(shared_ptr<Task> task){
        addTask(Clock::now()+task->timeOut, task);
    }
private:
    void addTask(const Clock::time_point time, std::shared_ptr<Task> t) {
        std::lock_guard<std::mutex> l(lock);
        tasks.emplace(time, std::move(t));
        sleeper.interrupt();
    }

    void manageTask(){
        // cout << "za hui shi!" << endl;
        // std::time_t now_c = std::chrono::system_clock::to_time_t(Clock::now());
        // cout << std::ctime(&now_c) << endl;
        std::lock_guard<std::mutex> l(lock);
        auto end_of_tasks_to_run = tasks.upper_bound(Clock::now());
        if(end_of_tasks_to_run != tasks.begin()) {
            for (auto i = tasks.begin(); i != end_of_tasks_to_run; ++i) {
                auto &task = (*i).second;

                thread (task->f).detach();
            }
        }
        tasks.erase(tasks.begin(), end_of_tasks_to_run);
    }
    std::multimap<Clock::time_point, std::shared_ptr<Task>> tasks;
    std::mutex lock;
    std::atomic<bool> done;
    shared_ptr<std::thread> checkThread;
    InterruptableSleep sleeper;

};
