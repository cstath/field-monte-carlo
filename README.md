# Field Monte Carlo #

This is a Field Monte Carlo simulator, that simulates a quantum complex scalar field on a 4-D space-time lattice. The action simulated by the software is the one of a relativistic bose gas at finite temperature and chemical potential, described in formula (1) at Gert Aart's relevant [paper](https://arxiv.org/abs/0810.2089). The action has a complex value, and thus is suffering from a [numerical sign problem](https://en.wikipedia.org/wiki/Numerical_sign_problem).

The tactic used for the stochastic simulation of the field is the [Reweighting procedure](https://en.wikipedia.org/wiki/Numerical_sign_problem#Reweighting_procedure). The [Metropolis](https://en.wikipedia.org/wiki/Metropolis%E2%80%93Hastings_algorithm) algorithm is utilized in order to simulate the "phase quenched" model of the system, and measure respective observable quantities. Observables measured are the average squared field, the average particle density, and the imaginary part of the action. Using this output data, the respective quantities for the full model can be reconstructed.

This software was developed as a part of my Master's thesis under the supervision of Prof. Konstantinos Anagnostopoulos (NTUA), and is provided under the MIT licence.

In case somebody is interested in the code, feel free to contact me at christos.stathopoulos@gmail.com.

## Installation ##

Open a command line in linux.

Clone the repository issuing

`git clone https://cstath@bitbucket.org/cstath/field-monte-carlo.git`

Change into the directory field-monte-carlo

`cd field-monte-carlo`

Build the executable with

`make`

Change into the executable's directory

`cd bin`

Run the program to get usage info

`./metropolis`

## Documentation ##

In order to create an html Doxygen documentation run

`make doc`
