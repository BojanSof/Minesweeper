cmake_minimum_required(VERSION 3.18)

include(CPM)

CPMAddPackage(
	NAME SFML
	GITHUB_REPOSITORY SFML/SFML
	GIT_TAG 2.5.1
	EXCLUDE_FROM_ALL true
	OPTIONS
		"SFML_STATIC_LIBRARIES OFF"
		"BUILD_SHARED_LIBS ON"
)