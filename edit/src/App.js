import { useState } from 'react';
import {Image} from "image-js"
import './App.css';
import { useRef } from 'react';

function App() {
  const [image, setImage] = useState(null);
  const [result, setResult] = useState(null);
  const input = useRef(null);

  function handleChange() {
    if (input.current.files && input.current.files[0]) {
      setImage(URL.createObjectURL(input.current.files[0]))
    }
  }

  async function handleClick()  {
    const img = await Image.load(image);

    setResult(img.grey().toDataURL());
  }

  return (
    <div className="App">
      <input type="file" onChange={handleChange} ref={input}></input>
      <br />
      <img src={image}></img>
      <button onClick={handleClick}>Grayscale</button>
      <img src={result}></img>
    </div>
  );
}

export default App;
