# Water-Filling: An Efficient Algorithm for Digitized Document Shadow Removal

<div class="row">
  <div class="column">
    <img src="examples/original_14_small.png" width="150" alt="original">
    <p>Original.</p>
  </div>
  
  <div class="column">
    <img src="examples/bako_14_small.png" width="150" alt="bako">
    <p>Bako et al.</p>
  </div>
  
  <div class="column">
    <img src="examples/kligler_14_small.png" width="150" alt="kligler">
    <p>Kligler et al.</p>
  </div>
  
  <div class="column">
    <img src="examples/sternberg_14_small.png" width="150" alt="sternberg">
    <p>Sternberg et al.</p>
  </div>
  
</div>

<div class="row">
  <div class="column">
    <img src="examples/tableau_14_small.png" width="150" alt="tableau">
    <p>Tableau et al.</p>
  </div>
  <div class="column">
    <img src="examples/zhang_14_small.png" width="150" alt="zhang">
    <p>Zhang et al.</p>
  </div>
  <div class="column">
    <img src="examples/ours_14_small.png" width="150" alt="water">
    <p><b>Water-Filling.</b></p>
  </div>
  <div class="column">
    <img src="examples/gt_14_small.png" width="150" alt="gt">
    <p>GroundTruth</p>
  </div>
</div>


My second year project under advisor Prof. Changick Kim (2015.09~2016.03). The technique is for removing illumination distortions for camera captured document images. Project funded by Hancom company.

Related papers is accepted:
Seungjun Jung, Muhammad Abul Hasan, and Changick Kim, <a target = "_blank" href="http://arxiv.org/abs/1904.09763">"Water-Filling: An Efficient Algorithm for Digitized Document Shadow Removal,"</a> ACCV, December 2018.

Benchmark dataset:
<a target = "_blank" href="https://www.dropbox.com/s/dngblakxcvc6ced/0525-supp.zip?dl=0"> Supplemental materials</a>

Project Funded by Hancom Inc.

<h2> Requirements </h2>

opencv 3.0 <br>
c++ <br>
<br>
<br>
### Thanks
Thank you <a target = "_blank" href="https://www.csie.ntu.edu.tw/~cyy/publications/papers/Lin2020BAD.pdf">Yun-Hsuan Lin</a>, and <a target = "_blank" href="https://ieeexplore.ieee.org/abstract/document/9053378">Jian-Ren Wang</a> for citing my work!
<br><br>
In 2016 ACCV, Bako, and I talked that this field only gets a few public attention. Now I am glad that many people are showing interest on this work.
<br><br>

### Note
Source Code Available, but do not use it (for industrial purpose) without permission. (Patent Issue ... ) <br>
Please ask any question if you have : seungjun45@kaist.ac.kr <br>
Sample Results are also Available.
<br>
<br>
### Tips
(2020/04/22) For those who are interested in applying this method in printed colored documents (i.e., magazine), <a target = "_blank" href="https://github.com/seungjun45/Water-Filling/issues/2">"alexliyang"</a> suggests that spliting image channels would help improving performance. (Thank you!)
