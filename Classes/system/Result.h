#ifndef __SYSTEM_RESULT_H__
#define __SYSTEM_RESULT_H__

#include <string>

using namespace std;

/**
 * @brief A generic result of function execution
 *        S = succcess
 *        E = error
 */
template <typename S, typename E>
class Result
{
    public:
        bool isSucceeded;
        S success;
        E error;

        void setSuccess(S success);
        void setError(E error);
};

template <typename S, typename E>
void Result<S, E>::setSuccess(S success)
{
    this->success = success;
    this->isSucceeded = true;
}

template <typename S, typename E>
void Result<S, E>::setError(E error)
{
    this->error = error;
    this->isSucceeded = false;
}

#endif