import os, subprocess, sys, time

build_dir = "build"

def build_project():
    if os.path.isdir(build_dir) != True:
        start_time = time.time()

        print(f"[INFO]: Configuring Cmake")
        subprocess.run(['cmake', '-B', build_dir])

        end_time = time.time()
        elapsed_time = end_time - start_time
        print(f"[INFO]: CMake Generation Time: {elapsed_time:.2f} second")

    print(f"[INFO]: {build_dir} directory already exists")

    print("[INFO]: Changing Directory")
    os.chdir(build_dir)

    start_time = time.time()

    print("[INFO]: Configuring Makefile")
    subprocess.run(['make', '-B', '-j', str(os.cpu_count())])

    end_time = time.time()
    elapsed_time = end_time - start_time
    print(f"[INFO]: Build Time: {elapsed_time:.2f} second")

def run_project():

    if os.path.isdir(build_dir) != True:
        build_project()

    start_time = time.time()

    exe_name = f"{build_dir}/qb"
    test_name = 'test.qb'
    print(f"[INFO]: Running: {exe_name} {test_name}")
    subprocess.run([exe_name, test_name])

    end_time = time.time()
    elapsed_time = end_time - start_time
    print(f"[INFO]: Run time: {elapsed_time:.2f} milliseconds")



def main():
    if len(sys.argv) == 1:
        print("[INFO]: Building the project")
        build_project()
        sys.exit(0)

    cli_arg = sys.argv[1]

    if cli_arg not in ['build', 'run']:
        print("[USAGE]: python script.py [build(optional)|run]")
        sys.exit(1)

    if cli_arg == "run":
        run_project()
    else:
        build_project()

if __name__ == "__main__":
    main()
