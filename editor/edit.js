import { Image }  from "./node_modules/image-js/src/image/Image"


execute().catch(console.error);

async function execute() {
  let image = await IJS.Image.load('cat.jpg');
  let grey = image
    .grey() // convert the image to greyscale.
    .resize({ width: 200 }) // resize the image, forcing a width of 200 pixels. The height is computed automatically to preserve the aspect ratio.
    .rotate(30); // rotate the image clockwise by 30 degrees.
    document.querySelector('img').src = grey.toDataURL();
}