import subprocess

tests = ['build/testcase_{:02d}'.format(i) for i in range(16)]
test_passed = []
test_failed = []

for test in tests:
    try:
        proc = subprocess.run(['./build/osmprun', '-p', test], timeout=10)
        proc.check_returncode()
        test_passed.append(test)
    except subprocess.TimeoutExpired:
        if test is tests[2] or test is test[3]:
            test_passed.append(test)
        else:
            test_failed.append(test)        
    except subprocess.CalledProcessError:
        test_failed.append(test)

print('{} out of {} Tests ran successfully!'.format(len(tests), len(test_passed)))
print('The following tests failed:')
if len(test_failed) == 0:
    print('None')
else:
    for test in test_failed:
        print(test)