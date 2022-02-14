#ifndef EPROSIMACLIENTTEST_H_
#define EPROSIMACLIENTTEST_H_

#include "EprosimaClient.h"
#include <chrono>

class EprosimaClientTest
{

public:

    EprosimaClientTest();

    virtual ~EprosimaClientTest();

    double run(
        int samples);

private:

    EprosimaClient m_client;

    std::chrono::time_point<std::chrono::steady_clock> m_t1, m_t2;

    double m_overhead;
};

#endif /* EPROSIMACLIENTTEST_H_ */