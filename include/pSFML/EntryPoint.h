
#pragma once

int main()
{
    auto simulation = psf::createSimulation();
    simulation->run();
    delete simulation;

    return 0;
}
