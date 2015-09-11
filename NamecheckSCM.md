# Namecheck SCM #

Mercurial repository will have at least 3 permanent branches:

- **Default:** holds the latest tested version of the project. It is subject to a weekly code integration (could be a Drop or Release depending on project stage). New features are merged from development and bug fixes are merged from hotfix (it is up to the developers to update the development branch when a bug is fixed).

- **Development:** is used to integrate features for the next release or drop and could have many branches depending on how many features are being developed.

- **Hotfix:**  has the latest code from Default plus bug fixes; bug fixing should be performed and committed here until a decision is made to merge its changes into the Default branch.

For every new User Story or Functionality, the developer in charge will create a new branch cloning the Development branch. When the new feature is complete, this branch will be reintegrated with the Development branch, never with the Default branch.

For bug fixes, a branch will be created by cloning the Hotfix branch, to where the code will be reintegrated once the bug is fixed. As before, there is no direct merging into the Default branch.

# Basic branch usage #

```
development	                      A--B--C--D--E
                                    /              \
default      ---R100-------R101---R101-----------R200-------
               	 \          /	
hotfix		   A-------B
```


# User Story branch usage #
```
user_story_1	                      A---B---C
			            /	       \
development	                    A---B---C---D---E
			           /	            \
default     ---R100-------R101---R101--------------R200--------
               	 \         /	
hotfix		  A-------B
```


# Intermediate branch usage #
```
development	                  A-----B---C---*-----D
				 /            /        \
master	  ---R200--------R201--R201---------R202-----R300--------
     	       \	  /	  \          /
hotfix		A-------B	   C--------D
```

`*` This means that the development branch was updated with all new bug fixes before integration with the default branch.

# Code Tagging #
In order to follow a basic versioning convention, every release will be identified by a two part name:

R.N

Where:

**R** is a “Release” string.

**N** is a release number.