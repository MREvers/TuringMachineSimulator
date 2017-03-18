#pragma once
class TMSimulator
{
public:
   TMSimulator();
   ~TMSimulator();

   /* sim_loop
   *  Main loop of this program.
   *  Requests a TM to build, and an input, then runs the simulation.
   *  Upon completion, requests more input.
   */
   void sim_loop();

private:

};