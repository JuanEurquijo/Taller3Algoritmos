project('experiments', 'cpp',
  version : '0.1')

options = [
	'optimization=0',
	'warning_level=3',
    'cpp_std=c++17'
	]

subdir('algorithms')
sources += files('experiments.cpp')

exe = executable(
	'experiments',
	sources,
	override_options: options)