$(document).ready(function(){
    
//----------------START OF JS CODE-----------------
    
//----------------TEST ON #leftDiv---------------- 
    
//Opacity fadeIn on 1 image div : #leftDiv 
    
    $("#leftDiv").on('mouseenter', function(){
        $("#leftDiv").css({'opacity':'1'}).animate({'opacity':'0.9'},250, function(){
        });
    });
    
     $("#leftDiv").on('mouseleave', function(){
        $("#leftDiv").css({'opacity':'0.9'}).animate({'opacity':'1'},800, function(){
        });
    });

//Animate + fadeIn + fadeOut for every Title in : #leftDiv 
    
$("#leftDiv").on("mouseenter", function(){
   $('#Discover').css({'display':'block', 'opacity':'0'}).animate({'opacity':'1','top':'250'}, 500);
  });
    
  $("#leftDiv").on("mouseleave", function(){
    $("#Discover").animate({'top':'400'}, 600);
    $("#Discover").css({'opacity':'1'}).animate({'opacity':'0','top':'100'}, 200);  
  });
    
//Opacity fadeIn on 2 images divs : .rightDivs
    
    $(".rightDivs").on('mouseenter', function(){
        $(this).css({'opacity':'1'}).animate({'opacity':'0.9'},250, function(){
        });
    });
    
     $(".rightDivs").on('mouseleave', function(){
        $(this).css({'opacity':'0.9'}).animate({'opacity':'1'},250, function(){
        });
    });
    
//Animate + fadeIn + fadeOut for every Title in : #rightTopDivs
    
$("#rightTopDiv").on("mouseenter", function(){
   $('#Explore').css({'display':'block', 'opacity':'0'}).animate({'opacity':'1','top':'150'}, 500);
  });
    
  $("#rightTopDiv").on("mouseleave", function(){
    $("#Explore").animate({'top':'+=140'}, 600);
    $("#Explore").css({'opacity':'1'}).animate({'opacity':'0','top':'-=200'}, 200);  
  });
        

//----------------END OF JS CODE----------------------------------------
});

