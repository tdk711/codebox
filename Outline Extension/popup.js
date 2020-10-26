'use strict';

let Bypass = document.getElementById("bypass");

Bypass.onclick = function()
 {
  chrome.tabs.query({active: true, currentWindow: true}, function(tabs) {
      
        let  originalURL = tabs[0].url;
       var  newURL = originalURL.replace("https://","https://outline.com/");
       chrome.tabs.create({"url": newURL});
       chrome.tabs.remove(tabs[0].id);
        
    } );

  };