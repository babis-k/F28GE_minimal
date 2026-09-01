import os
import pathlib
import shutil
import sys
    
def replace_in_file( filename, src, tgt):
    text = open(filename,'rt').read()
    text2 = text.replace(src, tgt)
    if text2 != text:
        open(filename,'wt').write(text2)

if __name__ == "__main__":
    
    cwd = pathlib.Path().resolve()
    
    src_project_name = "SFMLTemplate"
    dst_project_name = "MyNewSFMLApp"
    
    if len(sys.argv) == 1:
        print("Project name not specified, defaulting to ", dst_project_name)
    else:
        dst_project_name = sys.argv[1]
        
    dst_project_name = dst_project_name.replace(' ','_')
    dst_project_mainfile_basename = dst_project_name + ".cpp"
    
    src_folder = f"{cwd}/projects/{src_project_name}"
    dst_folder = f"{cwd}/projects/{dst_project_name}"
    dst_cmakelists_filename = f"{dst_folder}/CMakeLists.txt"
   
    if os.path.isdir(dst_folder):
        print(f"Project {dst_project_name} already exists, in {dst_folder}. Please choose another name")
        sys.exit(0)
        
    # Copy 'src_dir' to 'dest_dir', creating all intermediate directories
    shutil.copytree(src_folder, dst_folder, dirs_exist_ok=False)
    shutil.move(f'{dst_folder}/src/{src_project_name}.cpp', f'{dst_folder}/src/{dst_project_mainfile_basename}')    
    
    replace_in_file(dst_cmakelists_filename, src_project_name, dst_project_name)
    
    # Add the new subdirectory
    s = "# New subdirectories here..."
    replace_in_file("CMakeLists.txt", s, f"add_subdirectory(projects/{dst_project_name})\n{s}")
    
    print(f"Project {dst_project_name} has been created, you can find it in {dst_folder}")
