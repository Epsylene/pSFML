
#ifndef SIRIUSENGINE_ENTRYPOINT_H
#define SIRIUSENGINE_ENTRYPOINT_H

int main()
{
    auto simulation = srs::createSimulation();
    simulation->run();
    delete simulation;

    return 0;
}

#endif //SIRIUSENGINE_ENTRYPOINT_H
