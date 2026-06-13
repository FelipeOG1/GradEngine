#include "ops/ops.h"
#include <vector>
#include <memory>


class AutoGradEngine {
private:
    AutoGradEngine() {}
public:
    AutoGradEngine(const AutoGradEngine&) = delete;
    AutoGradEngine& operator=(const AutoGradEngine&) = delete;
    

    static AutoGradEngine& get_instance() {
        static AutoGradEngine instance;
        return instance;
    }
    

    
};
