sudo apt-get install git
git config --global user.name "haitao"
git config --global user.email  acer_yuhaitao@163.com

ssh-keygen  ##一直默认就可以了 
ssh-rsa 
linux@ubuntu:~/Git/project$ git config --global user.name "haitao"
linux@ubuntu:~/Git/project$ git config --global user.email  acer_yuhaitao@163.com
linux@ubuntu:~/Git/project$ cat ~/.gitconfig
[user]
	name = haitao
	email = acer_yuhaitao@163.com
[color]
	ui = always
linux@ubuntu:~/Git/project$  git commit -m '1st commit'
[master (root-commit) 453855d] 1st commit
 1 file changed, 9 insertions(+)
 create mode 100644 main.c
linux@ubuntu:~/Git/project$ rm -rf main.c 
linux@ubuntu:~/Git/project$ ls
linux@ubuntu:~/Git/project$ git checkout -f HEAD
linux@ubuntu:~/Git/project$ ls
main.c

git init
在linux下搭建git环境
1、创建Github账号，https://github.com
2、Linux创建SSH密钥：
[plain] view plain copy
ssh-keygen  ##一直默认就可以了  
3、将公钥加入到Github账户信息Account Settings->SSH Key
4、测试验证是否成功。
[plain] view plain copy
ssh -T git@github.com  
Hi someone! You've successfully authenticated, but GitHub does not provide shell access.  

同步github到本地
1、复制项目到本地：
[plain] view plain copy
git clone git://github.com:xxxx/test.git ##以gitreadonly方式克隆到本地，只可以读  
git clone git@github.com:xxx/test.git  ##以SSH方式克隆到本地，可以读写  
git clone https://github.com/xxx/test.git ##以https方式克隆到本地，可以读写  
git fetch git@github.com:xxx/xxx.git  ##获取到本地但不合并  
git pull git@github.com:xxx/xxx.git ##获取并合并内容到本地  

本地提交项目到github
1、本地配置
[plain] view plain copy
git config --global user.name 'onovps'  
git config --global user.email 'onovps@onovps.com' #全局联系方式，可选  
2、新建Git项目并提交到Github。
[plain] view plain copy
mkdir testdir & cd testdir  
touch README.md  
git init #初始化一个本地库  
git add README.md #添加文件到本地仓库  
git rm README.md #本地倒库内删除  
git commit -m "first commit" #提交到本地库并备注，此时变更仍在本地。  
git commit -a  ##自动更新变化的文件，a可以理解为auto  
git remote add xxx git@github.com:xxx/xxx.git  #增加一个远程服务器的别名。 
 git remote add haitao git@github.com:acer-haitao/Haitao.git
git remote rm xxx   ##删除远程版本库的别名  
git remote -v

git push -u haitao master #将本地文件提交到Github的remoname版本库中。此时才更新了本地变更到github服务上。  

分支版本操作
1、创建和合并分支
[plain] view plain copy
git branch #显示当前分支是master  
git branch new-feature  #创建分支  
git checkout new-feature  #切换到新分支  
vi page_cache.inc.php  
git add page_cache.inc.php  
git commit -a -m "added initial version of page cache"  
git push origin new-feature  ##把分支提交到远程服务器，只是把分支结构和内容提交到远程，并没有发生和主干的合并行为。  
2、如果new-feature分支成熟了，觉得有必要合并进master
[plain] view plain copy
git checkout master  #切换到新主干  
git merge new-feature  ##把分支合并到主干  
git branch #显示当前分支是master  
git push  #此时主干中也合并了new-feature的代码  

vim /etc/hosts

192.30.253.112 github.com
ssh-add .ssh/my_heroku_key_rsa

