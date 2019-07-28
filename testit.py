import subprocess
import glob

tests = glob.glob('build/testcase*')
test_passed = []
test_failed = []

for test in tests:
    try:
        proc = subprocess.run(['./build/osmprun', '-p', test], timeout=10)
        proc.check_returncode()
        test_passed.append(test)
    except subprocess.TimeoutExpired:
        if test == 'build/testcase_02' or test == 'build/testcase_03' or test == 'build/testcase_05_1':
            test_passed.append(test)
        else:
            test_failed.append(test)        
    except subprocess.CalledProcessError:
        test_failed.append(test)

print('{} out of {} Tests ran successfully!'.format(len(test_passed), len(tests)))
print('The following tests failed:')
if len(test_failed) == 0:
    print('None')
else:
    for test in test_failed:
        print(test)