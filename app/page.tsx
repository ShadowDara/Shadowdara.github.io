import { BlogPosts } from 'app/components/posts'

export default function Page() {
  return (
    <section>
      <h1 className="mb-8 text-2xl font-semibold tracking-tighter">
        Shadowdara's Page
      </h1>
      <p className="mb-4">
        {
          `Hey,
          I am a develeper and here on my site i am posting some stuff about my recent projects :)`
        }
      </p>
      <p>
        I currently learning a lot new Stuff but maybe check out what i made already ;)
      </p>
      <p>
        Feel free to contact me - Discord: Shadowdara
      </p>
      <div className="my-8">
        <BlogPosts />
      </div>
    </section>
  )
}
