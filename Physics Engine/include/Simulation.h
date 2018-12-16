#ifndef SIMULATION_H
#define SIMULATION_H


class Simulation
{
    public:
        Simulation(GLunit width, GLuint height);
        ~Simulation();
        void Update(GLFloat dt);
        void Render();
    protected:

    private:
};

#endif // SIMULATION_H
