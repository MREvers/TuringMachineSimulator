#pragma once
#include <vector>
#include "MachineTape.h"
#include "TransitionFunction.h"
#include "DChar.h"
#include "DString.h"

enum STEPRESULT { SUCCESS = 1, FAILED = 0, ACCEPT = 2, REJECT = -1 };

class TuringMachine
{
public:
   TuringMachine(int iNumTapes);
   ~TuringMachine();

   /* initialize
   *  Declare the start state, end state and beginning head position for this turing machine.
   *  iHeadPos is good for if you want to simulate a doubly infinite TM by starting in the 
   *  middle of the tape.
   */
   void initialize(std::string szStartState, std::string szEndState, int iHeadPos);

   /* getDrawState
   *  Returns a vector of strings representing each of the turing machine tapes.
   */
   std::vector<std::string> getDrawState() const;

   /* includeTransitionFunction
   *  Manually includes a transition function in the TF set of this turing machine
   */
   bool includeTransitionFunction(TransitionFunction* tf);

   /* includeEndState
   *  Manually declare a state that will cause this tm to cease computation - an accept state.
   */
   void includeEndState(std::string szEndState);

   /* getLastStepResult
   *  Returns string representation whether the last step ended on an accept state, reject state, or interim.
   */
   std::string getLastStepResult() const;

   /* getState
   *  Returns the current state of the turing machine.
   */
   std::string getState() const;

   /* setInput #1
   *  The input of a multi-tape turing machine is considered to be the state of the
   *  first tape of the machine. Thus, this sets the state of the first tape.
   */
   void setInput(std::string szInput);

   /* setInput #2
   *  The input of a multi-tape turing machine is considered to be the state of the
   *  first tape of the machine. Thus, this sets the state of the first tape.
   */
   void setInput(DString szInput);

   /* stepForward
   *  Looks for a transition function machine the current state and performs it.
   *  Returns false if fail to find.
   */
   bool stepForward();

   /* performTransitionFunction
   *  Mutates the state of the TM in conformance with the tf. Returns the result.
   */
   STEPRESULT performTransitionFunction(TransitionFunction* tf);

private:
   int m_iNumTapes;
   std::vector<MachineTape*> m_lstTapes;
   STEPRESULT m_LastStepResult;

   std::string m_szStartState;
   std::vector<std::string> m_szEndStates;
   std::vector<DChar*> m_lstInputLibrary;
   std::vector<DChar*> m_lstTapeLibrary;
   std::vector<TransitionFunction*> m_lstTransitionSet;

   std::string m_szCurrentState;

   bool checkAccept() const;
};

