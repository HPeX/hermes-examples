Boundary Layer (Elliptic)
-------------------------

This example is a singularly perturbed problem with known exact solution that exhibits a thin boundary layer 
The reader can use it to perform various experiments with adaptivity. The sample numerical results presented 
below imply that:

* One should always use anisotropically refined meshes for problems with boundary layers.
* hp-FEM is vastly superior to h-FEM with linear and quadratic elements. 
* One should use not only spatially anisotropic elements, but also polynomial anisotropy (different polynomial orders in each direction) for problems in boundary layers. 

Model problem
~~~~~~~~~~~~~

Equation solved: Poisson equation 

.. math::
    :label: layer-boundary

       -\Delta u + K^2 u - f = 0.

Domain of interest: Square $(-1, 1)^2$.

Boundary conditions: zero Dirichlet.

Exact solution
~~~~~~~~~~~~~~

.. math::

    u(x,y) = \hat u(x) \hat u(y)

where $\hat u$ is the exact solution of the 1D singularly-perturbed problem

.. math::

    -u'' + K^2 u = K^2

in $(-1,1)$ with zero Dirichlet boundary conditions. This solution has the form 

.. math::

    \hat u (x) = 1 - [exp(Kx) + exp(-Kx)] / [exp(K) + exp(-K)];

Right-hand side
~~~~~~~~~~~~~~~

Calculated by inserting the exact solution into the equation. 

Sample solution
~~~~~~~~~~~~~~~

.. figure:: benchmark-layer-boundary/solution.png
   :align: center
   :scale: 40% 
   :figclass: align-center
   :alt: Solution.

Below we present a series of convergence comparisons. Note that the error plotted
is the true approximate error calculated wrt. the exact solution given above.

Convergence comparison for isotropic refinements
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Let us first compare the performance of h-FEM (p=1), h-FEM (p=2) and hp-FEM with **isotropic** refinements:

Final mesh (h-FEM, p=1, isotropic refinements):

.. figure:: benchmark-layer-boundary/mesh_h1_iso.png
   :align: center
   :scale: 40% 
   :figclass: align-center
   :alt: Final mesh.

Final mesh (h-FEM, p=2, isotropic refinements):

.. figure:: benchmark-layer-boundary/mesh_h2_iso.png
   :align: center
   :scale: 40% 
   :figclass: align-center
   :alt: Final mesh.

Final mesh (hp-FEM, isotropic refinements):

.. figure:: benchmark-layer-boundary/mesh_hp_iso.png
   :align: center
   :scale: 40% 
   :figclass: align-center
   :alt: Final mesh.

DOF convergence graphs:

.. figure:: benchmark-layer-boundary/conv_compar_dof_iso.png
   :align: center
   :scale: 50% 
   :figclass: align-center
   :alt: DOF convergence graph.

CPU convergence graphs:

.. figure:: benchmark-layer-boundary/conv_compar_cpu_iso.png
   :align: center
   :scale: 50% 
   :figclass: align-center
   :alt: CPU convergence graph.

Convergence comparison for anisotropic refinements
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Next we compare the performance of h-FEM (p=1), h-FEM (p=2) and hp-FEM with **anisotropic** refinements:

Final mesh (h-FEM, p=1, anisotropic refinements):

.. figure:: benchmark-layer-boundary/mesh_h1_aniso.png
   :align: center
   :scale: 40% 
   :figclass: align-center
   :alt: Final mesh.

Final mesh (h-FEM, p=2, anisotropic refinements):

.. figure:: benchmark-layer-boundary/mesh_h2_aniso.png
   :align: center
   :scale: 40% 
   :figclass: align-center
   :alt: Final mesh.

Final mesh (hp-FEM, anisotropic refinements):

.. figure:: benchmark-layer-boundary/mesh_hp_aniso.png
   :align: center
   :scale: 40% 
   :figclass: align-center
   :alt: Final mesh.

DOF convergence graphs:

.. figure:: benchmark-layer-boundary/conv_compar_dof_aniso.png
   :align: center
   :scale: 50% 
   :figclass: align-center
   :alt: DOF convergence graph.

CPU convergence graphs:

.. figure:: benchmark-layer-boundary/conv_compar_cpu_aniso.png
   :align: center
   :scale: 50% 
   :figclass: align-center
   :alt: CPU convergence graph.

h-FEM (p=1): comparison of isotropic and anisotropic refinements
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

DOF convergence graphs:

.. figure:: benchmark-layer-boundary/conv_compar_dof_h1.png
   :align: center
   :scale: 50% 
   :figclass: align-center
   :alt: DOF convergence graph.

CPU convergence graphs:

.. figure:: benchmark-layer-boundary/conv_compar_cpu_h1.png
   :align: center
   :scale: 50% 
   :figclass: align-center
   :alt: CPU convergence graph.

h-FEM (p=2): comparison of isotropic and anisotropic refinements
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

DOF convergence graphs:

.. figure:: benchmark-layer-boundary/conv_compar_dof_h2.png
   :align: center
   :scale: 50% 
   :figclass: align-center
   :alt: DOF convergence graph.

CPU convergence graphs:

.. figure:: benchmark-layer-boundary/conv_compar_cpu_h2.png
   :align: center
   :scale: 50% 
   :figclass: align-center
   :alt: CPU convergence graph.

hp-FEM: comparison of isotropic and anisotropic refinements
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

In the hp-FEM one has two kinds of anisotropy -- spatial and polynomial. In the following,
"iso" means isotropy both in h and p, "aniso h" means anisotropy in h only, and 
"aniso hp" means anisotropy in both h and p. 

DOF convergence graphs (hp-FEM):

.. figure:: benchmark-layer-boundary/conv_compar_dof_hp.png
   :align: center
   :scale: 55% 
   :figclass: align-center
   :alt: DOF convergence graph.

CPU convergence graphs (hp-FEM):

.. figure:: benchmark-layer-boundary/conv_compar_cpu_hp.png
   :align: center
   :scale: 55% 
   :figclass: align-center
   :alt: CPU convergence graph.

The reader can see that enabling polynomially anisotropic refinements in the hp-FEM is 
equally important as allowing spatially anisotropic ones. 
