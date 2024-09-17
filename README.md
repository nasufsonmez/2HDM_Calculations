**README: 2HDMC to MADGRAPH LHA File Generator Script**

**Overview**

This script leverages the 2HDMC (Two-Higgs-Doublet Model Calculator) software to compute **LHA** (Les Houches Accord) files, which are then used as input for the **MADGRAPH** event generator. 
The purpose is to automate the generation of LHA files for various parameter sets in the Two-Higgs-Doublet Model (2HDM), facilitating high-energy physics simulations and event generation with MADGRAPH.

**Prerequisites**

Before running the script, ensure the following are installed and properly configured on your system:

**2HDMC**: A tool for calculating theoretical predictions in the Two-Higgs-Doublet Model.
**MADGRAPH**: A tool for simulating high-energy physics events.
**Python**: (or any language used in your script).
**Bash**: For shell script execution (if applicable).

**Installation Guide for 2HDMC**
Download and install 2HDMC from the official website.
Follow the installation instructions for your system (Linux, macOS, etc.).

**MADGRAPH Installation**
Download and install MADGRAPH from the official site.
Follow the setup guide to ensure MADGRAPH is configured correctly.

**Script Features**
Automated Parameter Scanning: The script automates the process of scanning over the parameter space of the Two-Higgs-Doublet Model (2HDM).
LHA File Generation: It outputs LHA files, compliant with the SLHA format, ready for use in MADGRAPH simulations.
Customizable Parameters: Users can define the 2HDM parameters (such as masses, couplings, mixing angles) to explore various model configurations.

**How to Use**

There are various calculations in **src** folder.

1. calc_decayWidths_flavourphysics.cpp
2. check_STU_potStability.cpp
3. check_decayWidth.cpp
4. **calc_LHA_files**.cpp  (will produce LHA files, named according to the parameter sets used, which are fully compatible with MADGRAPH for event generation.)
5. Demo_Ahrib.cpp
6. check_STU_neuralnetwork.cpp
7. calc_LHA_files_v2.cpp
8. check_STUparams.cpp
9. check_constraints_decayWidth.cpp

These files can be supplied to MADGRAPH for event generation and the decay tables which it needs.

